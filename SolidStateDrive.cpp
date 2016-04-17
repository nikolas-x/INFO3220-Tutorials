#include "SolidStateDrive.h"

SolidStateDrive::SolidStateDrive()
{

}

SolidStateDrive::SolidStateDrive(const std::string &name, int size) : HardDrive(name, size)
{

}

SolidStateDrive::SolidStateDrive(const SolidStateDrive &hardDrive) : HardDrive(hardDrive.m_name, hardDrive.m_size)
{

}

SolidStateDrive::~SolidStateDrive()
{

}
