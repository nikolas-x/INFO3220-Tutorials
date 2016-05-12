QT += core
QT -= gui

CONFIG += c++11

TARGET = Tutorial-5
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    BluRayDrive.cpp \
    Case.cpp \
    Computer.cpp \
    CoolingFan.cpp \
    CPU.cpp \
    DVDDrive.cpp \
    GraphicsCard.cpp \
    GraphicsCardSet.cpp \
    HardDiscDrive.cpp \
    HardDriveSet.cpp \
    Motherboard.cpp \
    PartAllocator.cpp \
    PowerSupply.cpp \
    Ram.cpp \
    RamSet.cpp \
    SolidStateDrive.cpp \
    WaterCooling.cpp \
    ComputerBuilder.cpp \
    GamingComputerBuilder.cpp \
    OfficeComputerBuilder.cpp \
    ServerBuilder.cpp

HEADERS += \
    BluRayDrive.h \
    Case.h \
    Computer.h \
    ComputerParts.h \
    ComputerPlan.h \
    CoolingFan.h \
    CPU.h \
    DiscDrive.h \
    DVDDrive.h \
    GraphicsCard.h \
    GraphicsCardSet.h \
    HardDiscDrive.h \
    HardDrive.h \
    HardDriveSet.h \
    Motherboard.h \
    Part.h \
    PartAllocator.h \
    PowerSupply.h \
    Ram.h \
    RamSet.h \
    SolidStateDrive.h \
    WaterCooling.h \
    ComputerBuilder.h \
    GamingComputerBuilder.h \
    OfficeComputerBuilder.h \
    ServerBuilder.h
