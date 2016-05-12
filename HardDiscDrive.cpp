#include "HardDiscDrive.h"

HardDiscDrive::HardDiscDrive() {}

HardDiscDrive::HardDiscDrive(const std::string &name, int size, int spinSpeed)
    : HardDrive(name, size)
    , m_spinSpeed(spinSpeed) {}

HardDiscDrive::HardDiscDrive(const HardDiscDrive &hardDrive)
    : HardDrive(hardDrive.m_name, hardDrive.m_size)
    , m_spinSpeed(hardDrive.m_spinSpeed) {}

HardDiscDrive::~HardDiscDrive() {}

std::string HardDiscDrive::getPartInformation() const
{
    std::string partInformation = this->HardDrive::getPartInformation();
    char spinSpeed[5];
    sprintf(spinSpeed, "%d", m_spinSpeed);
    partInformation += ", " + std::string(spinSpeed) + " RPM";
    return partInformation;
}

int HardDiscDrive::getSpinSpeed() const
{
    return m_spinSpeed;
}
