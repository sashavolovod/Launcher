QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = servicebox
TEMPLATE = app

SOURCES += main.cpp \
    runguard.cpp

HEADERS  += \
    runguard.h

CONFIG += c++11

RESOURCES += \
    launcher.qrc

win32:RC_ICONS += images/if_package_settings_1441.ico
