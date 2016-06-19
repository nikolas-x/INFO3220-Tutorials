#include "SolidStateDrive.h"

SolidStateDrive::SolidStateDrive()
    : Part()
    , HardDrive()
{

}

SolidStateDrive::SolidStateDrive(const std::string &name, int size)
    : Part(name)
    , HardDrive(name, size)
{

}

SolidStateDrive::SolidStateDrive(const SolidStateDrive &hardDrive)
    : Part(hardDrive.m_name)
    , HardDrive(hardDrive.m_name, hardDrive.m_size)
{

}

SolidStateDrive::~SolidStateDrive()
{

}
