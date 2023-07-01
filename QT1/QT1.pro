QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apple.cpp \
    boomb.cpp \
    bullet.cpp \
    enemy.cpp \
    heroplane.cpp \
    main.cpp \
    map.cpp \
    mypushbutton.cpp \
    mywidget.cpp \
    otherscene.cpp \
    successscene.cpp

HEADERS += \
    apple.h \
    boomb.h \
    bullet.h \
    config.h \
    enemy.h \
    heroplane.h \
    map.h \
    mypushbutton.h \
    mywidget.h \
    otherscene.h \
    successscene.h

FORMS += \
    mywidget.ui

RESOURCES += res.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


