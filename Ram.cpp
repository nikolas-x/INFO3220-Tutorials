#include "Ram.h"

Ram::Ram()
    : Part()
    , RequiredPart()
{

}

Ram::Ram(const std::string &name, int speed, int size)
    : Part(name)
    , RequiredPart()
    , m_speed(speed)
    , m_size(size)
{

}

Ram::Ram(const Ram& ram)
    : Part(ram.m_name)
    , RequiredPart()
    , m_speed(ram.m_speed)
    , m_size(ram.m_size)
{

}

Ram::~Ram()
{

}

std::string Ram::getPartInformation() const
{
    char frequency[5];
    itoa(m_speed, frequency, 10);

    char size[5];
    itoa(m_size, size, 10);

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

void Ram::accept(Visitor* visitor)
{
    visitor->visit(this);
}
