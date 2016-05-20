#include "CPU.h"

CPU::CPU()
    : RequiredPart()
{

}

CPU::CPU(const std::string &name, double clockSpeed, const std::string &socketType)
    : RequiredPart(name)
    , m_clockSpeed(clockSpeed)
    , m_socketType(socketType)
{

}

CPU::CPU(const CPU &cpu)
    : RequiredPart(cpu.m_name)
    , m_clockSpeed(cpu.m_clockSpeed)
    , m_socketType(cpu.m_socketType)
{

}

CPU::~CPU()
{

}

std::string CPU::getPartInformation() const
{
    char clockSpeed[5];
    sprintf(clockSpeed, "%.1lf", m_clockSpeed);
    std::string partInformation (m_name + ", Clock Speed: " + std::string(clockSpeed) + " Ghz, Socket: " + m_socketType);
    return partInformation;
}

void CPU::accept(Visitor* visitor)
{
    //TODO
}

