#include "logindialog.h"
#include "adminmainwindow.h"
#include "teachermainwindow.h"
#include "studentmainwindow.h"
#include "databasemanager.h"
#include <QApplication>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 构建数据库路径：项目根目录/studentmanager.db
    QString dbPath = QDir::currentPath() + "/../../../studentmanager.db";
    dbPath = QDir::cleanPath(dbPath);  // 规范化路径
    
    qDebug() << "当前工作目录:" << QDir::currentPath();
    qDebug() << "数据库路径:" << dbPath;
    qDebug() << "数据库文件是否存在:" << QFile::exists(dbPath);

    // 初始化数据库
    if (!DatabaseManager::instance().connect(dbPath)) {
        QMessageBox::critical(nullptr, "错误", 
            QString("数据库连接失败\n路径: %1\n\n请确保已运行 python init_database.py 生成数据库文件").arg(dbPath));
        return -1;
    }

    // 注意：不要调用 initializeTables()，因为数据库已经由 Python 脚本初始化
    // 如果调用会创建空表，导致无法登录

    // 显示登录对话框
    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted) {
        User user = loginDialog.getLoggedInUser();

        // 根据用户角色显示对应的主窗口
        QMainWindow* mainWindow = nullptr;

        if (user.role() == "admin") {
            mainWindow = new AdminMainWindow(user);
        } else if (user.role() == "teacher") {
            mainWindow = new TeacherMainWindow(user);
        } else if (user.role() == "student") {
            mainWindow = new StudentMainWindow(user);
        }

        if (mainWindow) {
            mainWindow->show();
            int result = a.exec();
            delete mainWindow;
            return result;
        }
    }

    return 0;
}
