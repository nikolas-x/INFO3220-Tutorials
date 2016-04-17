#include "Motherboard.h"

Motherboard::Motherboard()
{

}

Motherboard::Motherboard(const std::string &name, const std::string &socketType, int numberOfRamSlots, int numberOfGraphicsCardSlots)
    : Part(name), m_socketType(socketType), m_numberOfRamSlots(numberOfRamSlots), m_numberOfGraphicsCardSlots(numberOfGraphicsCardSlots)
{
}

Motherboard::Motherboard(const Motherboard &motherboard)
    : Part(motherboard.m_name), m_socketType(motherboard.m_socketType),
      m_numberOfRamSlots(motherboard.m_numberOfRamSlots),
      m_numberOfGraphicsCardSlots(motherboard.m_numberOfGraphicsCardSlots)
{

}

Motherboard::~Motherboard()
{

}

std::string Motherboard::getPartInformation() const
{
    char numberOfRamSolts[5];
    sprintf(numberOfRamSlots, "%d", m_numberOfRamSlots);
    char numberOfGraphicsCardSlots[5];
    sprintf(numberOfGraphicsCardSlots, "%d", m_numberOfGraphicsCardSlots);

    std::string partInformation ("Motherboard: " + m_name + ", Socket: " + m_socketType + "\n");
    partInformation += "No. of Ram Slots: " + std::string(numberOfRamSolts) + ", No. of Graphics Cards Permitted: " + std::string(numberOfGraphicsCardSlots);
    return partInformation;
}
