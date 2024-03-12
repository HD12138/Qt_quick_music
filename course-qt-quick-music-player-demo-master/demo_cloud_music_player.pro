QT += quick
QT       += core gui
QT += quickwidgets
QT       += core gui qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App.cpp \
    admindialog.cpp \
    alldata.cpp \
    dialog.cpp \
    httputils.cpp \
    mainwindow.cpp \
    userdialog.cpp \
    visitormode.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    admindialog.h \
    alldata.h \
    dialog.h \
    httputils.h \
    mainwindow.h \
    userdialog.h \
    visitormode.h

FORMS += \
    admindialog.ui \
    dialog.ui \
    mainwindow.ui \
    userdialog.ui \
    visitormode.ui
