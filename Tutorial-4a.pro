QT += core
QT -= gui

CONFIG += c++11

TARGET = Tutorial-4a
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Singleton.cpp \
    UserInterface.cpp

HEADERS += \
    Singleton.h \
    UserInterface.h
