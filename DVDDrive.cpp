#include "DVDDrive.h"

DVDDrive::DVDDrive()
    : Part()
    , DiscDrive()
{

}

DVDDrive::DVDDrive(const std::string &name, int readSpeed)
    : Part(name)
    , DiscDrive(name, readSpeed)
{

}

DVDDrive::DVDDrive(const DVDDrive &discDrive)
    : Part(discDrive.m_name)
    , DiscDrive(discDrive.m_name, discDrive.m_readSpeed)
{

}

DVDDrive::~DVDDrive()
{

}

std::string DVDDrive::getPartInformation() const
{
    std::string partInformation = this->DiscDrive::getPartInformation();
    partInformation.replace(0, 12, "DVD Drive: ");
    return partInformation;
}
