#include "BluRayDrive.h"

BluRayDrive::BluRayDrive()
    : Part()
    , DiscDrive()
{

}

BluRayDrive::BluRayDrive(const std::string &name, int readSpeed)
    : Part(name)
    , DiscDrive(name, readSpeed)
{

}

BluRayDrive::BluRayDrive(const BluRayDrive &discDrive)
    : Part(discDrive.m_name)
    , DiscDrive(discDrive.m_name, discDrive.m_readSpeed)
{

}

BluRayDrive::~BluRayDrive()
{

}

std::string BluRayDrive::getPartInformation() const
{
    std::string partInformation = this->DiscDrive::getPartInformation();
    partInformation.replace(0, 12, "Blu-ray Drive: ");
    return partInformation;
}
