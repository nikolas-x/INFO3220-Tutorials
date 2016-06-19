#include "HardDiscDrive.h"

HardDiscDrive::HardDiscDrive()
    : Part()
    , HardDrive()
{

}

HardDiscDrive::HardDiscDrive(const std::string &name, int size, int spinSpeed)
    : Part(name)
    , HardDrive(name, size)
    , m_spinSpeed(spinSpeed)
{

}

HardDiscDrive::HardDiscDrive(const HardDiscDrive &hardDrive)
    : Part(hardDrive.m_name)
    , HardDrive(hardDrive.m_name, hardDrive.m_size)
    , m_spinSpeed(hardDrive.m_spinSpeed)
{

}

HardDiscDrive::~HardDiscDrive()
{

}

std::string HardDiscDrive::getPartInformation() const
{
    std::string partInformation = this->HardDrive::getPartInformation();

    char spinSpeed[5];
    itoa(m_spinSpeed, spinSpeed, 10);

    partInformation += ", " + std::string(spinSpeed) + " RPM";

    return partInformation;
}

int HardDiscDrive::getSpinSpeed() const
{
    return m_spinSpeed;
}
