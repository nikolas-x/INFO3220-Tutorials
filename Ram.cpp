#include "Ram.h"

Ram::Ram()
{

}

Ram::Ram(const std::string &name, int speed, int size)
    : Part(name), m_speed(speed), m_size(size)
{

}

Ram::Ram(const Ram& ram)
    : Part(ram.m_name), m_speed(ram.m_speed), m_size(ram.m_size)
{

}

Ram::~Ram()
{

}

std::string Ram::getPartInformation() const
{
    char frequency[5];
    sprintf(frequency, "%d", m_speed);

    char size[5];
    sprintf(size, "%d", m_size);

    std::string partInformation(m_name + ", Frequency: " + frequency + " Mhz, Size: " + size + " GB");

    return partInformation;
}

int Ram::getRamSpeed() const
{
    return m_speed;
}

int Ram::getRamSize() const
{
    return m_size;
}
