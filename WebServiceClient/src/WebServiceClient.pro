#-------------------------------------------------
#
# Project created by QtCreator 2019-03-04T07:03:10
#
#-------------------------------------------------

QT += core gui widgets network xml

TARGET = WebServiceClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        loginwindow.cpp \
    servicewindow.cpp \
    validation.cpp \
    user.cpp \
    mainlogin.cpp \
    networkapi.cpp \
    product.cpp \
    category.cpp

HEADERS += \
        loginwindow.h \
    servicewindow.h \
    validation.h \
    user.h \
    mainlogin.h \
    networkapi.h \
    product.h \
    category.h

FORMS += \
        loginwindow.ui \
    servicewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    TestWebService/TestWebService.pro
