#include "CPU.h"

CPU::CPU() {}

CPU::CPU(const std::string &name, double clockSpeed, const std::string &socketType)
    : Part(name)
    , m_clockSpeed(clockSpeed)
    , m_socketType(socketType) {}

CPU::CPU(const CPU &cpu)
    : Part(cpu.m_name)
    , m_clockSpeed(cpu.m_clockSpeed)
    , m_socketType(cpu.m_socketType) {}

CPU::~CPU() {}

std::string CPU::getPartInformation() const
{
    std::stringstream ss;
    ss << "CPU: " << m_name << ", Clock Speed: " << std::setprecision(2) << m_clockSpeed << " Ghz, Socket: " << m_socketType;
    return ss.str();
}
