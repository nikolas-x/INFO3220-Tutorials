QT += core
QT -= gui

CONFIG += c++11

TARGET = Tutorial-2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    car.cpp \
    bus.cpp \
    bicycle.cpp

HEADERS += \
    vehicle.h \
    motorvehicle.h \
    car.h \
    bus.h \
    bicycle.h
