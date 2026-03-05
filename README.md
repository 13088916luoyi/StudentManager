# 学生管理系统

基于Qt框架开发的学生管理系统，支持管理员、教师、学生三种角色。

## 功能特性

- 用户注册和登录（支持三种角色）
- 密码SHA-256加密存储
- 学生信息管理（增删改查）
- 教师信息管理（增删改查）
- 课程信息管理（增删改查）
- 成绩信息管理（增删改查）
- 基于角色的权限控制

## 技术栈

- Qt 5.12+ (Core, GUI, Widgets, SQL, Charts)
- C++17
- SQLite 3.x
- qmake

## 快速开始

### 1. 初始化数据库

**重要**：首次运行前必须生成数据库文件！

```bash
python init_database.py
```

这将在项目根目录创建 `studentmanager.db` 文件，包含测试账号和示例数据。

### 2. 编译运行

在Qt Creator中：
1. 打开 `StudentManager.pro` 项目文件
2. 构建项目（Ctrl+B）
3. 运行程序（Ctrl+R）

程序启动时会显示数据库路径和加载状态，请查看控制台输出确认。

### 3. 登录测试

使用以下测试账号登录：

| 用户名 | 密码 | 角色 | 说明 |
|--------|------|------|------|
| admin | admin123 | 管理员 | 拥有所有权限 |
| teacher1 | teacher123 | 教师 | 张教授 |
| teacher2 | teacher123 | 教师 | 李老师 |
| teacher3 | teacher123 | 教师 | 王老师 |
| student1 | student123 | 学生 | 张三 |
| student2 | student123 | 学生 | 李四 |
| student3 | student123 | 学生 | 王五 |
| student4 | student123 | 学生 | 赵六 |
| student5 | student123 | 学生 | 孙七 |

## 项目结构

```
StudentManager/
├── include/                   # 头文件目录
│   ├── databasemanager.h      # 数据库管理器
│   ├── user.h                 # 用户模型
│   ├── student.h              # 学生模型
│   ├── teacher.h              # 教师模型
│   ├── course.h               # 课程模型
│   ├── grade.h                # 成绩模型
│   ├── userdao.h              # 用户数据访问
│   ├── studentdao.h           # 学生数据访问
│   ├── teacherdao.h           # 教师数据访问
│   ├── coursedao.h            # 课程数据访问
│   ├── gradedao.h             # 成绩数据访问
│   ├── passwordhasher.h       # 密码加密工具
│   ├── permissionmanager.h    # 权限管理器
│   ├── authcontroller.h       # 认证控制器
│   ├── studentcontroller.h    # 学生管理控制器
│   ├── teachercontroller.h    # 教师管理控制器
│   ├── coursecontroller.h     # 课程管理控制器
│   ├── gradecontroller.h      # 成绩管理控制器
│   ├── logindialog.h          # 登录对话框
│   ├── registerdialog.h       # 注册对话框
│   ├── adminmainwindow.h      # 管理员主窗口
│   ├── teachermainwindow.h    # 教师主窗口
│   └── studentmainwindow.h    # 学生主窗口
├── src/                       # 源文件目录
│   ├── main.cpp               # 程序入口
│   ├── databasemanager.cpp
│   ├── user.cpp
│   ├── student.cpp
│   ├── teacher.cpp
│   ├── course.cpp
│   ├── grade.cpp
│   ├── userdao.cpp
│   ├── studentdao.cpp
│   ├── teacherdao.cpp
│   ├── coursedao.cpp
│   ├── gradedao.cpp
│   ├── passwordhasher.cpp
│   ├── permissionmanager.cpp
│   ├── authcontroller.cpp
│   ├── studentcontroller.cpp
│   ├── teachercontroller.cpp
│   ├── coursecontroller.cpp
│   ├── gradecontroller.cpp
│   ├── logindialog.cpp
│   ├── registerdialog.cpp
│   ├── adminmainwindow.cpp
│   ├── teachermainwindow.cpp
│   └── studentmainwindow.cpp
├── ui/                        # UI文件目录
│   ├── mainwindow.ui
│   ├── logindialog.ui
│   ├── registerdialog.ui
│   ├── adminmainwindow.ui
│   ├── teachermainwindow.ui
│   └── studentmainwindow.ui
├── StudentManager.pro         # Qt项目配置文件
├── init_database.py           # 数据库初始化脚本
├── studentmanager.db          # SQLite数据库文件
└── README.md                  # 项目说明文档
```

## 数据库结构

系统使用SQLite数据库，包含以下数据表：

- `users` - 用户账号表
- `students` - 学生信息表
- `teachers` - 教师信息表
- `courses` - 课程信息表
- `grades` - 成绩信息表
- `course_students` - 选课关联表

## 系统架构

采用三层架构设计：

1. **表示层（UI Layer）**：Qt Widgets界面
2. **业务逻辑层（Business Layer）**：Controller控制器
3. **数据访问层（Data Access Layer）**：DAO数据访问对象

## 开发环境

- Qt Creator 4.x+
- Qt 5.12+ 或 Qt 6.x
- C++17编译器
- Python 3.6+（用于数据库初始化）

## 注意事项

1. **首次运行前必须生成数据库**：运行 `python init_database.py`
2. 数据库文件 `studentmanager.db` 必须放在项目根目录
3. 所有密码使用SHA-256加盐哈希加密存储
4. 系统支持跨平台运行（Windows/Linux/macOS）

## 常见问题

### Q: 提示"未找到用户"或"数据库连接失败"？
A: 数据库未生成。在项目根目录运行 `python init_database.py` 生成数据库文件。

### Q: 如何重置数据库？
A: 删除项目根目录的 `studentmanager.db` 文件，重新运行 `python init_database.py`。

## 许可证

本项目仅供学习和研究使用。
