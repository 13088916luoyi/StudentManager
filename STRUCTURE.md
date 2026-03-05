# 项目目录结构说明

## 目录组织

项目已按照标准的Qt项目结构进行重组：

### 📁 include/
存放所有头文件（.h）
- 24个头文件
- 包含所有类的声明和接口定义

### 📁 src/
存放所有源文件（.cpp）
- 24个源文件
- 包含所有类的实现代码
- main.cpp 程序入口

### 📁 ui/
存放所有界面文件（.ui）
- 6个UI文件
- Qt Designer设计的界面文件

### 📄 根目录文件
- `StudentManager.pro` - Qt项目配置文件
- `init_database.py` - 数据库初始化脚本
- `studentmanager.db` - SQLite数据库文件
- `README.md` - 项目说明文档

## 编译配置

在 `StudentManager.pro` 中已配置：

```qmake
INCLUDEPATH += include    # 头文件搜索路径
SOURCES += src/*.cpp      # 源文件路径
HEADERS += include/*.h    # 头文件路径
FORMS += ui/*.ui          # UI文件路径
```

## 优势

✅ **清晰的结构**：文件按类型分类，易于查找和管理

✅ **标准化**：符合Qt项目的标准目录结构

✅ **易于维护**：新增文件时只需放入对应目录

✅ **团队协作**：团队成员可以快速理解项目结构

## 注意事项

1. 源文件中的 `#include` 语句无需修改，Qt会自动在 `include/` 目录中查找头文件

2. 编译时Qt Creator会自动处理路径关系

3. 数据库文件 `studentmanager.db` 应与编译后的可执行文件在同一目录

## 文件统计

| 类型 | 数量 | 位置 |
|------|------|------|
| 头文件 | 24 | include/ |
| 源文件 | 24 | src/ |
| UI文件 | 6 | ui/ |
| 配置文件 | 1 | 根目录 |
| 脚本文件 | 1 | 根目录 |
| 文档文件 | 2 | 根目录 |

**总计**：58个项目文件
