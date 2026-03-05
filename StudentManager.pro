QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += include

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/databasemanager.cpp \
    src/user.cpp \
    src/student.cpp \
    src/teacher.cpp \
    src/course.cpp \
    src/grade.cpp \
    src/userdao.cpp \
    src/studentdao.cpp \
    src/teacherdao.cpp \
    src/coursedao.cpp \
    src/gradedao.cpp \
    src/passwordhasher.cpp \
    src/permissionmanager.cpp \
    src/authcontroller.cpp \
    src/studentcontroller.cpp \
    src/teachercontroller.cpp \
    src/coursecontroller.cpp \
    src/gradecontroller.cpp \
    src/logindialog.cpp \
    src/registerdialog.cpp \
    src/adminmainwindow.cpp \
    src/teachermainwindow.cpp \
    src/studentmainwindow.cpp \
    src/studentdialog.cpp \
    src/teacherdialog.cpp \
    src/coursedialog.cpp \
    src/gradedialog.cpp \
    src/teacherprofiledialog.cpp \
    src/gradeeditdialog.cpp \
    src/studentprofiledialog.cpp \
    src/courseselectiondialog.cpp \
    src/gradestatsdialog.cpp

HEADERS += \
    include/mainwindow.h \
    include/databasemanager.h \
    include/user.h \
    include/student.h \
    include/teacher.h \
    include/course.h \
    include/grade.h \
    include/userdao.h \
    include/studentdao.h \
    include/teacherdao.h \
    include/coursedao.h \
    include/gradedao.h \
    include/passwordhasher.h \
    include/permissionmanager.h \
    include/authcontroller.h \
    include/studentcontroller.h \
    include/teachercontroller.h \
    include/coursecontroller.h \
    include/gradecontroller.h \
    include/logindialog.h \
    include/registerdialog.h \
    include/adminmainwindow.h \
    include/teachermainwindow.h \
    include/studentmainwindow.h \
    include/studentdialog.h \
    include/teacherdialog.h \
    include/coursedialog.h \
    include/gradedialog.h \
    include/teacherprofiledialog.h \
    include/gradeeditdialog.h \
    include/studentprofiledialog.h \
    include/courseselectiondialog.h \
    include/gradestatsdialog.h

FORMS += \
    ui/mainwindow.ui \
    ui/logindialog.ui \
    ui/registerdialog.ui \
    ui/adminmainwindow.ui \
    ui/teachermainwindow.ui \
    ui/studentmainwindow.ui \
    ui/studentdialog.ui \
    ui/teacherdialog.ui \
    ui/coursedialog.ui \
    ui/gradedialog.ui \
    ui/teacherprofiledialog.ui \
    ui/gradeeditdialog.ui \
    ui/studentprofiledialog.ui \
    ui/courseselectiondialog.ui \
    ui/gradestatsdialog.ui

qnx: target.path = /tmp/${TARGET}/bin
else: unix:!android: target.path = /opt/${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
