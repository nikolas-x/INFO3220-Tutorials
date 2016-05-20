#include "CountingVisitor.h"

CountingVisitor::CountingVisitor()
{

}

CountingVisitor::~CountingVisitor()
{

}

void CountingVisitor::visit(VisitablePart* part)
{
    // TODO
}

void CountingVisitor::visit(Case* computerCase)
{
    // TODO
}

void CountingVisitor::visit(CoolingFan* coolingFan)
{
    // TODO
}

void CountingVisitor::visit(CPU* cpu)
{
    // TODO
}

void CountingVisitor::visit(DiscDrive* discDrive)
{
    // TODO
}

void CountingVisitor::visit(GraphicsCard* graphicsCard)
{
    // TODO
}

void CountingVisitor::visit(HardDrive* hardDrive)
{
    // TODO
}

void CountingVisitor::visit(Motherboard* motherboard)
{
    // TODO
}

void CountingVisitor::visit(PowerSupply* powerSupply)
{
    // TODO
}

void CountingVisitor::visit(Ram* ram)
{
    // TODO
}

void CountingVisitor::visit(WaterCooling* waterCooling)
{
    // TODO
}

unsigned int CountingVisitor::numberOfBluRayDrive() const
{
    return m_numberOfBluRayDrives;
}

unsigned int CountingVisitor::numberOfCoolingFans() const
{
    return m_numberOfCoolingFans;
}

unsigned int CountingVisitor::numberOfCases() const
{
    return m_numberOfCases;
}

unsigned int CountingVisitor::numberOfCPUs() const
{
    return m_numberOfCPUs;
}

unsigned int CountingVisitor::numberOfDVDDrives() const
{
    return m_numberOfDVDDrives;
}

unsigned int CountingVisitor::numberOfHardDrives() const
{
    return m_numberOfHardDrives;
}

unsigned int CountingVisitor::numberOfGraphicsCards() const
{
    return m_numberOfGraphicsCards;
}

unsigned int CountingVisitor::numberOfMotherboards() const
{
    return m_numberOfMotherboards;
}

unsigned int CountingVisitor::numberOfPowerSupplies() const
{
    return m_numberOfPowerSupplies;
}

unsigned int CountingVisitor::numberOfRamSticks() const
{
    return m_numberOfRamSticks;
}

unsigned int CountingVisitor::numberOfWaterCoolingUnits() const
{
    return m_numberOfWaterCoolingUnits;
}
