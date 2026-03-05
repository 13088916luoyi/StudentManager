#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
学生管理系统数据库初始化脚本
从module_project2目录读取标准数据文件生成studentmanager.db数据库
"""

import sqlite3
import hashlib
import uuid
import os
import re

DATA_DIR = 'module_project2'

def generate_salt():
    """生成随机盐值（与Qt的QUuid格式一致）"""
    return str(uuid.uuid4())

def hash_password(password, salt):
    """
    使用SHA-256加密密码（与Qt的实现完全一致）
    """
    data = (password + salt).encode('utf-8')
    hash_bytes = hashlib.sha256(data).digest()
    return hash_bytes.hex()

def create_database():
    """创建数据库和表结构"""
    conn = sqlite3.connect('studentmanager.db')
    cursor = conn.cursor()
    
    cursor.execute('DROP TABLE IF EXISTS teacher_courses')
    cursor.execute('DROP TABLE IF EXISTS grades')
    cursor.execute('DROP TABLE IF EXISTS courses')
    cursor.execute('DROP TABLE IF EXISTS teachers')
    cursor.execute('DROP TABLE IF EXISTS students')
    cursor.execute('DROP TABLE IF EXISTS users')
    
    cursor.execute('''
        CREATE TABLE users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username VARCHAR(50) UNIQUE NOT NULL,
            password VARCHAR(255) NOT NULL,
            salt VARCHAR(255) NOT NULL,
            role VARCHAR(20) NOT NULL CHECK(role IN ('admin', 'teacher', 'student')),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    ''')
    
    # 学生表
    cursor.execute('''
        CREATE TABLE students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER UNIQUE,
            student_no VARCHAR(20) UNIQUE NOT NULL,
            name VARCHAR(50) NOT NULL,
            class_name VARCHAR(50),
            major VARCHAR(100),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
        )
    ''')
    
    # 教师表
    cursor.execute('''
        CREATE TABLE teachers (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER UNIQUE,
            teacher_no VARCHAR(20) UNIQUE NOT NULL,
            name VARCHAR(50) NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
        )
    ''')
    
    # 课程表
    cursor.execute('''
        CREATE TABLE courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            course_no VARCHAR(20) UNIQUE NOT NULL,
            course_name VARCHAR(100) NOT NULL,
            credit REAL,
            hours INTEGER,
            course_type VARCHAR(20) CHECK(course_type IN ('必修', '选修')),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    ''')
    
    # 教师课程关联表
    cursor.execute('''
        CREATE TABLE teacher_courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            teacher_id INTEGER NOT NULL,
            course_id INTEGER NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (teacher_id) REFERENCES teachers(id) ON DELETE CASCADE,
            FOREIGN KEY (course_id) REFERENCES courses(id) ON DELETE CASCADE,
            UNIQUE(teacher_id, course_id)
        )
    ''')
    
    # 成绩表
    cursor.execute('''
        CREATE TABLE grades (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            student_id INTEGER NOT NULL,
            course_id INTEGER NOT NULL,
            grade REAL CHECK(grade >= 0 AND grade <= 100),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (student_id) REFERENCES students(id) ON DELETE CASCADE,
            FOREIGN KEY (course_id) REFERENCES courses(id) ON DELETE CASCADE,
            UNIQUE(student_id, course_id)
        )
    ''')
    
    cursor.execute('CREATE INDEX idx_students_student_no ON students(student_no)')
    cursor.execute('CREATE INDEX idx_grades_student_id ON grades(student_id)')
    cursor.execute('CREATE INDEX idx_grades_course_id ON grades(course_id)')
    cursor.execute('CREATE INDEX idx_teacher_courses_teacher_id ON teacher_courses(teacher_id)')
    cursor.execute('CREATE INDEX idx_teacher_courses_course_id ON teacher_courses(course_id)')
    
    conn.commit()
    return conn, cursor

def parse_students(filepath):
    """解析student.txt文件"""
    students = []
    with open(filepath, 'r', encoding='gbk') as f:
        for line in f:
            line = line.strip()
            if line.startswith('#') or line == '' or line == '#END':
                continue
            parts = line.split('\t')
            if len(parts) >= 4:
                student_no = parts[0].strip()
                name = parts[1].strip()
                class_name = parts[2].strip()
                major = parts[3].strip()
                students.append({
                    'student_no': student_no,
                    'name': name,
                    'class_name': class_name,
                    'major': major
                })
    return students

def parse_staff(filepath):
    """解析staff.txt文件，包含教师授课信息"""
    teachers = []
    with open(filepath, 'r', encoding='gbk') as f:
        for line in f:
            line = line.strip()
            if line.startswith('#') or line == '' or line == '#END':
                continue
            # 使用空格分割（文件中是用空格分隔的）
            parts = line.split()
            
            if len(parts) >= 2:
                teacher_no = parts[0].strip()
                name = parts[1].strip()
                # 第3列及以后是教授的课程
                courses = parts[2:] if len(parts) > 2 else []
                teachers.append({
                    'teacher_no': teacher_no,
                    'name': name,
                    'courses': courses
                })
    return teachers

def parse_modules(filepath):
    """解析module.txt文件"""
    courses = []
    with open(filepath, 'r', encoding='gbk') as f:
        for line in f:
            line = line.strip()
            if line.startswith('#') or line == '' or line == '#END':
                continue
            
            parts = re.split(r'[\t\s]+', line)
            parts = [p.strip() for p in parts if p.strip()]
            
            if len(parts) >= 4:
                course_no = parts[0]
                
                course_type = '必修'
                if len(parts) > 4:
                    last_part = parts[-1]
                    if last_part in ['必修', '选修']:
                        course_type = last_part
                        parts = parts[:-1]
                
                credit_str = parts[-2] if len(parts) >= 3 else '0'
                hours_str = parts[-1] if len(parts) >= 2 else '0'
                
                try:
                    credit = float(credit_str)
                except:
                    credit = 0.0
                
                try:
                    hours = int(hours_str)
                except:
                    hours = 0
                
                course_name = ' '.join(parts[1:-2]) if len(parts) > 3 else parts[1] if len(parts) > 1 else ''
                
                courses.append({
                    'course_no': course_no,
                    'course_name': course_name,
                    'credit': credit,
                    'hours': hours,
                    'course_type': course_type
                })
    return courses

def parse_scores(filepath):
    """解析score.txt文件"""
    scores = []
    with open(filepath, 'r', encoding='gbk') as f:
        for line in f:
            line = line.strip()
            if line.startswith('#') or line == '' or line == '#END':
                continue
            parts = line.split('\t')
            if len(parts) >= 4:
                student_no = parts[0].strip()
                course_name = parts[2].strip()
                try:
                    grade = float(parts[3].strip())
                except:
                    grade = 0.0
                scores.append({
                    'student_no': student_no,
                    'course_name': course_name,
                    'grade': grade
                })
    return scores

def insert_data(conn, cursor, students, teachers, courses, scores):
    """插入数据到数据库"""
    
    print("正在插入数据...")
    
    admin_salt = generate_salt()
    admin_password = hash_password('123456', admin_salt)
    cursor.execute('''
        INSERT INTO users (username, password, salt, role)
        VALUES (?, ?, ?, ?)
    ''', ('admin', admin_password, admin_salt, 'admin'))
    print("✓ 创建管理员账号: admin / 123456")
    
    student_ids = {}
    for s in students:
        salt = generate_salt()
        password = hash_password('123456', salt)
        cursor.execute('''
            INSERT INTO users (username, password, salt, role) 
            VALUES (?, ?, ?, ?)
        ''', (s['student_no'], password, salt, 'student'))
        user_id = cursor.lastrowid
        
        cursor.execute('''
            INSERT INTO students (user_id, student_no, name, class_name, major)
            VALUES (?, ?, ?, ?, ?)
        ''', (user_id, s['student_no'], s['name'], s['class_name'], s['major']))
        student_ids[s['student_no']] = cursor.lastrowid
    
    print(f"✓ 创建学生账号: {len(students)} 个 (密码均为: 123456)")
    
    # 先插入所有课程
    course_ids = {}
    for c in courses:
        cursor.execute('''
            INSERT INTO courses (course_no, course_name, credit, hours, course_type)
            VALUES (?, ?, ?, ?, ?)
        ''', (c['course_no'], c['course_name'], c['credit'], c['hours'], c['course_type']))
        course_ids[c['course_name']] = cursor.lastrowid
    
    print(f"✓ 创建课程: {len(courses)} 门")
    
    # 插入教师及其教授的课程
    teacher_ids = {}
    teacher_course_count = 0
    for t in teachers:
        salt = generate_salt()
        password = hash_password('123456', salt)
        cursor.execute('''
            INSERT INTO users (username, password, salt, role) 
            VALUES (?, ?, ?, ?)
        ''', (t['teacher_no'], password, salt, 'teacher'))
        user_id = cursor.lastrowid
        
        cursor.execute('''
            INSERT INTO teachers (user_id, teacher_no, name)
            VALUES (?, ?, ?)
        ''', (user_id, t['teacher_no'], t['name']))
        teacher_id = cursor.lastrowid
        teacher_ids[t['teacher_no']] = teacher_id
        
        # 插入教师教授的课程关联
        for course_name in t['courses']:
            course_id = course_ids.get(course_name)
            if course_id:
                try:
                    cursor.execute('''
                        INSERT INTO teacher_courses (teacher_id, course_id)
                        VALUES (?, ?)
                    ''', (teacher_id, course_id))
                    teacher_course_count += 1
                except sqlite3.IntegrityError:
                    pass  # 已存在的关联，跳过
    
    print(f"✓ 创建教师账号: {len(teachers)} 个 (密码均为: 123456)")
    print(f"✓ 建立教师-课程关联: {teacher_course_count} 条")
    
    grade_count = 0
    for s in scores:
        student_id = student_ids.get(s['student_no'])
        course_id = course_ids.get(s['course_name'])
        
        if student_id and course_id:
            try:
                cursor.execute('''
                    INSERT INTO grades (student_id, course_id, grade)
                    VALUES (?, ?, ?)
                ''', (student_id, course_id, s['grade']))
                grade_count += 1
            except sqlite3.IntegrityError:
                pass
    
    print(f"✓ 创建成绩记录: {grade_count} 条")
    
    conn.commit()

def print_summary(cursor):
    """打印数据库统计信息"""
    print("\n" + "="*60)
    print("数据库创建完成！统计信息：")
    print("="*60)
    
    cursor.execute("SELECT COUNT(*) FROM users")
    print(f"用户总数: {cursor.fetchone()[0]}")
    
    cursor.execute("SELECT COUNT(*) FROM students")
    print(f"学生总数: {cursor.fetchone()[0]}")
    
    cursor.execute("SELECT COUNT(*) FROM teachers")
    print(f"教师总数: {cursor.fetchone()[0]}")
    
    cursor.execute("SELECT COUNT(*) FROM courses")
    print(f"课程总数: {cursor.fetchone()[0]}")
    
    cursor.execute("SELECT COUNT(*) FROM teacher_courses")
    print(f"教师-课程关联: {cursor.fetchone()[0]}")
    
    cursor.execute("SELECT COUNT(*) FROM grades")
    print(f"成绩记录: {cursor.fetchone()[0]}")
    
    print("\n" + "="*60)
    print("测试账号信息：")
    print("="*60)
    print("管理员: admin / 123456")
    print("教师账号: 教师工号 / 123456")
    print("学生账号: 学号 / 123456")
    print("="*60)

def main():
    """主函数"""
    print("="*60)
    print("学生管理系统 - 数据库初始化工具")
    print("="*60)
    print()
    
    student_file = os.path.join(DATA_DIR, 'student.txt')
    staff_file = os.path.join(DATA_DIR, 'staff.txt')
    module_file = os.path.join(DATA_DIR, 'module.txt')
    score_file = os.path.join(DATA_DIR, 'score.txt')
    
    for f in [student_file, staff_file, module_file, score_file]:
        if not os.path.exists(f):
            print(f"✗ 错误: 找不到数据文件 {f}")
            return
    
    try:
        print("正在解析数据文件...")
        students = parse_students(student_file)
        print(f"  - 解析学生数据: {len(students)} 条")
        
        teachers = parse_staff(staff_file)
        print(f"  - 解析教师数据: {len(teachers)} 条")
        
        courses = parse_modules(module_file)
        print(f"  - 解析课程数据: {len(courses)} 条")
        
        scores = parse_scores(score_file)
        print(f"  - 解析成绩数据: {len(scores)} 条")
        print()
        
        print("正在创建数据库和表结构...")
        conn, cursor = create_database()
        print("✓ 数据库结构创建成功")
        print()
        
        insert_data(conn, cursor, students, teachers, courses, scores)
        print()
        
        print_summary(cursor)
        
        conn.close()
        print("\n✓ 数据库文件已保存: studentmanager.db")
        print("\n提示: 现在可以运行Qt程序进行测试")
        
    except Exception as e:
        print(f"\n✗ 错误: {e}")
        import traceback
        traceback.print_exc()

if __name__ == '__main__':
    main()
