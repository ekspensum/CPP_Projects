QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_alltests.cpp \
    ../src/validation.cpp \
    ../src/mainlogin.cpp \
    ../src/user.cpp

HEADERS += ../src/mainlogin.h

INCLUDEPATH += \
    ../src
