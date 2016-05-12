#include "WaterCooling.h"

WaterCooling::WaterCooling() {}

WaterCooling::WaterCooling(const std::string &name, const std::string &systemType)
    : Part(name)
    , m_systemType(systemType) {}

WaterCooling::WaterCooling(const WaterCooling &waterCooling)
    : Part(waterCooling.m_name)
    , m_systemType(waterCooling.m_systemType) {}

WaterCooling::~WaterCooling() {}

std::string WaterCooling::getPartInformation() const
{
    return std::string("Water Cooler: " + m_name + ", Cooling Type: " + m_systemType);
}
