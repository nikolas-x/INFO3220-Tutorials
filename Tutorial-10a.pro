QT += core
QT -= gui

CONFIG += c++11

TARGET = Tutorial-10a
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    GenericQueue.h \
    GenericStack.h \
    StackQueue.h
