QT += core
QT -= gui

CONFIG += c++11

TARGET = Tutorial-4b
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    date.cpp \
    student.cpp

HEADERS += \
    date.h \
    person.h \
    student.h
