#include "PowerSupply.h"

PowerSupply::PowerSupply()
    : Part("Generic Supply")
    , RequiredPart()
    , m_watts(550)
{

}

PowerSupply::PowerSupply(const std::string &name, int watts)
    : Part(name)
    , RequiredPart()
    , m_watts(watts)
{

}

PowerSupply::PowerSupply(const PowerSupply &powerSupply)
    : Part(powerSupply.m_name)
    , RequiredPart()
    , m_watts(powerSupply.m_watts)
{

}

PowerSupply::~PowerSupply()
{

}

std::string PowerSupply::getPartInformation() const
{
    char maximumPower[5];
    itoa(m_watts, maximumPower, 10);

    std::string partInformation ("Power Supply: " + m_name + ", Maximum Power: " + maximumPower + " Watts");
    return partInformation;
}

void PowerSupply::accept(Visitor* visitor)
{
    visitor->visit(this);
}
