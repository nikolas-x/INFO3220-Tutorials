#include "Computer.h"

Computer::Computer()
    : m_computerType("Generic Computer")
    , m_requiredParts(new Part*[numberOfRequiredParts])
    , m_additionalParts(0)
    , m_numberOfAdditionalParts(0)
    , m_numberOfAssignedAdditionalParts(0)

{
    m_requiredParts[CPUID] = new CPU();
    m_requiredParts[MotherboardID] = new Motherboard();
    m_requiredParts[RamSetID] = new Ram();
    m_requiredParts[HardDriveSetID] = new HardDrive();
    m_requiredParts[GraphicsCardSetID] = new GraphicsCard();
    m_requiredParts[CaseID] = new Case();
    m_requiredParts[PowerSupplyID] = new PowerSupply();
}

Computer::~Computer()
{
    for (int i = 0; i < numberOfRequiredParts; ++i)
    {
        delete m_requiredParts[i];
    }
    delete[] m_requiredParts;

    if (m_additionalParts != 0 && m_numberOfAdditionalParts != -1)
    {
        for (int i = 0; i < m_numberOfAssignedAdditionalParts; ++i)
        {
            delete m_additionalParts[i];
        }
        delete[] m_additionalParts;
    }

    m_additionalParts = 0;
    m_numberOfAdditionalParts = -1;
    m_numberOfAssignedAdditionalParts = 0;
}

const std::string &Computer::getComputerType() const
{
    return m_computerType;
}

const CPU &Computer::getCPU() const
{
    return dynamic_cast<const CPU&>(*m_requiredParts[CPUID]);
}

const Motherboard &Computer::getMotherboard() const
{
    return dynamic_cast<Motherboard&>(*m_requiredParts[MotherboardID]);
}

const RamSet &Computer::getRamSet() const
{
    return dynamic_cast<RamSet&>(*m_requiredParts[RamSetID]);
}

const HardDriveSet &Computer::getHardDriveSet() const
{
    return dynamic_cast<HardDriveSet&>(*m_requiredParts[HardDriveSetID]);
}

const GraphicsCardSet &Computer::getGraphicsCardSet() const
{
    return dynamic_cast<GraphicsCardSet&>(*m_requiredParts[GraphicsCardSetID]);
}

const PowerSupply &Computer::getPowerSupply() const
{
    return dynamic_cast<PowerSupply&>(*m_requiredParts[PowerSupplyID]);
}

const Case &Computer::getCase() const
{
    return dynamic_cast<Case&>(*m_requiredParts[CaseID]);
}

Part **Computer::getAdditionalPartsList() const
{
    return m_additionalParts;
}

int Computer::getNumberOfAdditionalParts() const
{
    return m_numberOfAdditionalParts;
}

std::string Computer::getComputerSpecifications() const
{
    std::stringstream ss;
    ss << m_computerType << std::endl;
    for (int i = 0; i < numberOfRequiredParts; ++i)
    {
        ss << m_requiredParts[i]->getPartInformation() << std::endl;
    }
    ss << "Additional Parts";
    for (int i = 0; i < m_numberOfAssignedAdditionalParts; ++i)
    {
        ss << std::endl
           << m_additionalParts[i]->getPartInformation();
    }

    return ss.str();
}

void Computer::setComputerType(const std::string &computerType)
{
    m_computerType = computerType;
}

void Computer::setCPU(const CPU &cpu)
{
    delete m_requiredParts[CPUID];
    m_requiredParts[CPUID] = new CPU(cpu);
}

void Computer::setMotherboard(const Motherboard &motherboard)
{
    delete m_requiredParts[MotherboardID];
    m_requiredParts[MotherboardID] = new Motherboard(motherboard);
}

void Computer::setRAM(Ram *ram, int numberOfRamSticks)
{
    delete m_requiredParts[RamSetID];
    m_requiredParts[RamSetID] = new RamSet(ram, numberOfRamSticks);
}

void Computer::setHardDrives(HardDrive **hardDrive, int numberOfHardDrives)
{
    delete m_requiredParts[HardDriveSetID];
    m_requiredParts[HardDriveSetID] = new HardDriveSet(hardDrive, numberOfHardDrives);
}

void Computer::setGraphicsCards(GraphicsCard *graphicsCard, int numberOfGraphicsCard)
{
    delete m_requiredParts[GraphicsCardSetID];
    m_requiredParts[GraphicsCardSetID] = new GraphicsCardSet(graphicsCard, numberOfGraphicsCard);
}

void Computer::setPowerSupply(const PowerSupply &powerSupply)
{
    delete m_requiredParts[PowerSupplyID];
    m_requiredParts[PowerSupplyID] = new PowerSupply(powerSupply);
}

void Computer::setCase(const Case &computerCase)
{
    delete m_requiredParts[CaseID];
    m_requiredParts[CaseID] = new Case(computerCase);
}

void Computer::setNumberOfAdditionalParts(int numberOfAdditionalParts)
{
    m_numberOfAdditionalParts = numberOfAdditionalParts;
    m_additionalParts = new Part*[numberOfAdditionalParts];
}

void Computer::addAdditionalPart(const Part &part)
{
    if (m_numberOfAssignedAdditionalParts < m_numberOfAdditionalParts)
    {
        m_additionalParts[m_numberOfAssignedAdditionalParts++] = PartAllocator::getPart(part);
    }
}
