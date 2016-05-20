#include "DiscDrive.h"

DiscDrive::DiscDrive()
    : OptionalPart()
{

}

DiscDrive::DiscDrive(const std::string &name, int readSpeed)
    : OptionalPart(name)
    , m_readSpeed(readSpeed)
{

}

DiscDrive::DiscDrive(const DiscDrive &discDrive)
    : OptionalPart(discDrive.m_name)
    , m_readSpeed(discDrive.m_readSpeed)
{

}


DiscDrive::~DiscDrive()
{

}

std::string DiscDrive::getPartInformation() const
{
    char speed[5];
    itoa(m_readSpeed, speed, 10);

    std::string partInformation("Disc Drive: " + m_name + ", Read Speed: " + speed + "X");

    return partInformation;
}

void DiscDrive::accept(Visitor* visitor)
{
    //TODO
}


