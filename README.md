# 学生管理系统

基于 Qt 6 和 SQLite 的学生管理系统，支持管理员、教师、学生三种角色。

## 项目概述

本项目是一个功能完善的学生信息管理系统，采用 C++ 和 Qt 框架开发，使用 SQLite 作为数据存储。系统支持三种用户角色：管理员、教师和学生，每种角色拥有不同的功能权限。

## 功能特性

### 管理员功能
- **学生管理**：添加、编辑、删除学生信息，查看学生列表
- **教师管理**：添加、编辑、删除教师信息，分配教授课程
- **课程管理**：添加、编辑、删除课程信息
- **成绩管理**：查看所有学生成绩，支持按课程筛选
- **账号管理**：查看系统所有用户账号

### 教师功能
- **个人信息**：查看和编辑个人基本信息
- **我的课程**：查看教授的课程列表
- **课程学生管理**：查看选修某课程的学生列表及成绩
- **成绩管理**：为学生录入和修改成绩

### 学生功能
- **个人信息**：查看和编辑个人基本信息
- **选课管理**：查看已选课程，选择新课程，退选课程
- **成绩查询**：查看所有课程成绩及统计信息（平均分、最高分、最低分）

## 技术架构

### 开发环境
- **开发框架**：Qt 6.10.1
- **编程语言**：C++17
- **数据库**：SQLite3
- **构建工具**：qmake / MinGW 64-bit
- **图表组件**：Qt Charts

### 项目结构
```
StudentManager/
├── include/                # 头文件
│   ├── adminmainwindow.h   # 管理员主窗口
│   ├── authcontroller.h    # 认证控制器
│   ├── course.h            # 课程实体类
│   ├── coursecontroller.h  # 课程控制器
│   ├── coursedao.h         # 课程数据访问对象
│   ├── courseselectiondialog.h  # 课程选择对话框
│   ├── databasemanager.h   # 数据库管理器
│   ├── grade.h             # 成绩实体类
│   ├── gradecontroller.h   # 成绩控制器
│   ├── gradedao.h          # 成绩数据访问对象
│   ├── loginwindow.h       # 登录窗口
│   ├── mainwindow.h        # 主窗口基类
│   ├── student.h           # 学生实体类
│   ├── studentcontroller.h # 学生控制器
│   ├── studentdao.h        # 学生数据访问对象
│   ├── studentmainwindow.h # 学生主窗口
│   ├── studentprofiledialog.h   # 学生信息编辑对话框
│   ├── teacher.h           # 教师实体类
│   ├── teachercontroller.h # 教师控制器
│   ├── teacherdao.h        # 教师数据访问对象
│   ├── teacherdialog.h     # 教师信息编辑对话框
│   ├── teachermainwindow.h # 教师主窗口
│   ├── teacherprofiledialog.h   # 教师信息编辑对话框
│   └── user.h              # 用户实体类
├── src/                    # 源文件
│   ├── adminmainwindow.cpp
│   ├── authcontroller.cpp
│   ├── coursecontroller.cpp
│   ├── coursedao.cpp
│   ├── courseselectiondialog.cpp
│   ├── databasemanager.cpp
│   ├── gradecontroller.cpp
│   ├── gradedao.cpp
│   ├── loginwindow.cpp
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── studentcontroller.cpp
│   ├── studentdao.cpp
│   ├── studentmainwindow.cpp
│   ├── studentprofiledialog.cpp
│   ├── teachercontroller.cpp
│   ├── teacherdao.cpp
│   ├── teacherdialog.cpp
│   ├── teachermainwindow.cpp
│   └── teacherprofiledialog.cpp
├── ui/                     # UI 文件
│   ├── adminmainwindow.ui
│   ├── courseselectiondialog.ui
│   ├── loginwindow.ui
│   ├── studentmainwindow.ui
│   ├── studentprofiledialog.ui
│   ├── teacherdialog.ui
│   ├── teacherprofiledialog.ui
│   └── teachermainwindow.ui
├── module_project2/        # 原始数据文件
│   ├── staff.txt           # 教师数据
│   ├── student.txt         # 学生数据
│   ├── module.txt          # 课程数据
│   └── score.txt           # 成绩数据
├── init_database.py        # 数据库初始化脚本
└── StudentManager.pro      # Qt 项目文件
```

## 数据库设计

### 数据表结构

#### users 表（用户表）
| 字段名 | 类型 | 说明 |
|--------|------|------|
| id | INTEGER | 主键，自增 |
| username | VARCHAR(50) | 用户名（学号/工号） |
| password | VARCHAR(255) | 加密后的密码 |
| salt | VARCHAR(255) | 密码盐值 |
| role | VARCHAR(20) | 角色（admin/teacher/student） |
| created_at | DATETIME | 创建时间 |
| updated_at | DATETIME | 更新时间 |

#### students 表（学生表）
| 字段名 | 类型 | 说明 |
|--------|------|------|
| id | INTEGER | 主键，自增 |
| user_id | INTEGER | 关联用户ID |
| student_no | VARCHAR(20) | 学号 |
| name | VARCHAR(50) | 姓名 |
| class_name | VARCHAR(50) | 班级 |
| major | VARCHAR(100) | 专业 |
| created_at | DATETIME | 创建时间 |
| updated_at | DATETIME | 更新时间 |

#### teachers 表（教师表）
| 字段名 | 类型 | 说明 |
|--------|------|------|
| id | INTEGER | 主键，自增 |
| user_id | INTEGER | 关联用户ID |
| teacher_no | VARCHAR(20) | 工号 |
| name | VARCHAR(50) | 姓名 |
| created_at | DATETIME | 创建时间 |
| updated_at | DATETIME | 更新时间 |

#### courses 表（课程表）
| 字段名 | 类型 | 说明 |
|--------|------|------|
| id | INTEGER | 主键，自增 |
| course_no | VARCHAR(20) | 课程号 |
| course_name | VARCHAR(100) | 课程名 |
| credit | REAL | 学分 |
| hours | INTEGER | 学时 |
| course_type | VARCHAR(20) | 课程类别（必修/选修） |
| created_at | DATETIME | 创建时间 |
| updated_at | DATETIME | 更新时间 |

#### teacher_courses 表（教师课程关联表）
| 字段名 | 类型 | 说明 |
|--------|------|------|
| id | INTEGER | 主键，自增 |
| teacher_id | INTEGER | 教师ID |
| course_id | INTEGER | 课程ID |
| created_at | DATETIME | 创建时间 |

#### grades 表（成绩表）
| 字段名 | 类型 | 说明 |
|--------|------|------|
| id | INTEGER | 主键，自增 |
| student_id | INTEGER | 学生ID |
| course_id | INTEGER | 课程ID |
| grade | REAL | 成绩（0-100） |
| created_at | DATETIME | 创建时间 |
| updated_at | DATETIME | 更新时间 |

## 快速开始

### 环境要求
- Qt 6.10.1 或更高版本
- MinGW 64-bit 编译器
- Python 3.x（用于初始化数据库）

### 构建步骤

1. **克隆项目**
```bash
git clone <repository-url>
cd StudentManager
```

2. **初始化数据库**
```bash
python init_database.py
```
这将根据 `module_project2/` 目录下的原始数据文件创建 SQLite 数据库。

3. **使用 Qt Creator 打开项目**
   - 打开 `StudentManager.pro` 文件
   - 配置编译套件（MinGW 64-bit）
   - 构建并运行

### 默认账号

系统初始化后会创建以下默认账号：

| 角色 | 账号 | 密码 |
|------|------|------|
| 管理员 | admin | 123456 |
| 教师 | 教师工号（如：023423） | 123456 |
| 学生 | 学号（如：20081003516） | 123456 |

## 设计模式

本项目采用以下设计模式：

### 1. MVC 模式
- **Model**：实体类（Student, Teacher, Course, Grade, User）
- **View**：UI 界面文件（.ui）
- **Controller**：控制器类（*Controller）处理业务逻辑

### 2. DAO 模式（Data Access Object）
- 每个实体类对应一个 DAO 类
- 封装数据库操作，实现数据访问层与业务逻辑层分离

### 3. 单例模式
- `DatabaseManager`：管理数据库连接
- `AuthController`：管理用户认证状态

## 安全特性

- **密码加密**：使用 SHA-256 + 随机盐值加密存储
- **SQL 注入防护**：使用参数化查询
- **输入验证**：对所有用户输入进行有效性检查

## 界面特性

- **响应式布局**：自适应窗口大小
- **现代化 UI**：采用扁平化设计风格
- **表格优化**：
  - 鼠标悬停显示单元格完整内容
  - 固定行号列宽度，防止两位数行号挤在一起
  - 选中行高亮显示
- **数据验证**：表单提交前进行完整性检查

## 数据导入

系统支持从文本文件导入初始数据：

- **staff.txt**：教师信息（工号、姓名、教授课程）
- **student.txt**：学生信息（学号、姓名、班级、专业）
- **module.txt**：课程信息（课程号、课程名、学分、学时、类别）
- **score.txt**：成绩信息（学号、姓名、课程名、成绩）

数据文件使用 GBK 编码，以制表符或空格分隔字段。

## 贡献指南

欢迎提交 Issue 和 Pull Request。

## 许可证

本项目仅供学习交流使用。

## 更新日志

### v1.0.0
- 实现基础的学生管理系统功能
- 支持管理员、教师、学生三种角色
- 实现课程管理和成绩管理功能
- 添加数据导入功能
- 优化用户界面和交互体验
