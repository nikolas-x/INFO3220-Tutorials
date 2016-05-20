#include "HardDrive.h"

HardDrive::HardDrive()
    : RequiredPart()
{

}

HardDrive::HardDrive(const std::string &name, int size)
    : RequiredPart(name)
    , m_size(size)
{

}

HardDrive::HardDrive(const HardDrive &hardDrive)
    : RequiredPart(hardDrive.m_name)
    , m_size(hardDrive.m_size)
{

}

HardDrive::~HardDrive()
{

}

std::string HardDrive::getPartInformation() const
{
    char size[5];
    itoa(m_size, size, 10);

    std::string partInformation(m_name + ", Size: " + size + " GB");

    return partInformation;
}

int HardDrive::getHardDriveSize()
{
    return m_size;
}

void HardDrive::accept(Visitor* visitor)
{
    //TODO
}
