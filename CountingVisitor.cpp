#include "CountingVisitor.h"
#include "ComputerParts.h"

CountingVisitor::CountingVisitor()
    : m_numberOfBluRayDrives(0)
    , m_numberOfCoolingFans(0)
    , m_numberOfCases(0)
    , m_numberOfCPUs(0)
    , m_numberOfDVDDrives(0)
    , m_numberOfHardDrives(0)
    , m_numberOfGraphicsCards(0)
    , m_numberOfMotherboards(0)
    , m_numberOfPowerSupplies(0)
    , m_numberOfRamSticks(0)
    , m_numberOfWaterCoolingUnits(0)
{

}

CountingVisitor::~CountingVisitor()
{

}

void CountingVisitor::visit(VisitablePart* part)
{
    part->accept(this);
}

void CountingVisitor::visit(BluRayDrive* bluRayDrive)
{
    Q_UNUSED(bluRayDrive);
    ++m_numberOfBluRayDrives;
}

void CountingVisitor::visit(Case* computerCase)
{
    Q_UNUSED(computerCase);
    ++m_numberOfCases;
}

void CountingVisitor::visit(CoolingFan* coolingFan)
{
    Q_UNUSED(coolingFan);
    ++m_numberOfCoolingFans;
}

void CountingVisitor::visit(CPU* cpu)
{
    Q_UNUSED(cpu);
    ++m_numberOfCPUs;
}

void CountingVisitor::visit(DiscDrive* discDrive)
{
    if (BluRayDrive* bluRayDrive = dynamic_cast<BluRayDrive*>(discDrive))
    {
        visit(bluRayDrive);
    }
    if (DVDDrive* dvdDrive = dynamic_cast<DVDDrive*>(discDrive))
    {
        visit(dvdDrive);
    }
}

void CountingVisitor::visit(DVDDrive* dvdDrive)
{
    Q_UNUSED(dvdDrive);
    ++m_numberOfDVDDrives;
}

void CountingVisitor::visit(GraphicsCard* graphicsCard)
{
    Q_UNUSED(graphicsCard);
    ++m_numberOfGraphicsCards;
}

void CountingVisitor::visit(HardDrive* hardDrive)
{
    Q_UNUSED(hardDrive);
    ++m_numberOfHardDrives;
}

void CountingVisitor::visit(Motherboard* motherboard)
{
    Q_UNUSED(motherboard);
    ++m_numberOfMotherboards;
}

void CountingVisitor::visit(PowerSupply* powerSupply)
{
    Q_UNUSED(powerSupply);
    ++m_numberOfPowerSupplies;
}

void CountingVisitor::visit(Ram* ram)
{
    Q_UNUSED(ram);
    ++m_numberOfRamSticks;
}

void CountingVisitor::visit(WaterCooling* waterCooling)
{
    Q_UNUSED(waterCooling);
    ++m_numberOfWaterCoolingUnits;
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
