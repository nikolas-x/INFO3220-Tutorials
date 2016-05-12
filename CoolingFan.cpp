#include "CoolingFan.h"

CoolingFan::CoolingFan() {}

CoolingFan::CoolingFan(const std::string &name, int fanSpeed)
    : Part(name)
    , m_fanSpeed(fanSpeed) {}

CoolingFan::CoolingFan(const CoolingFan &coolingFan)
    : Part(coolingFan.m_name)
    , m_fanSpeed(coolingFan.m_fanSpeed) {}

CoolingFan::~CoolingFan() {}

std::string CoolingFan::getPartInformation() const
{
    char speed[5];
    sprintf(speed, "%d", m_fanSpeed);
    std::string partInformation("Cooling Fan: " + m_name + ", Speed: " + speed + " RPM");
    return partInformation;
}
