#include "GamingComputerBuilder.h"

GamingComputerBuilder::GamingComputerBuilder() : ComputerBuilder()
{

}

GamingComputerBuilder::~GamingComputerBuilder()
{

}

void GamingComputerBuilder::createComputer()
{
    m_computer = new Computer();
    m_computer->setComputerType("Gaming Computer");
    this->ComputerBuilder::createComputer();
}

void GamingComputerBuilder::addCPU()
{
    CPU cpu ("Intel Celeron G1610 Ivy Bridge Dual-Core", 2.6, "LGA 1155");
    m_computer->setCPU(cpu);
}

void GamingComputerBuilder::addMotherboard()
{
    Motherboard motherboard("ASUS P8H61-M LE/CSM R2.0", "LGA 1155", 2, 1);
    m_computer->setMotherboard(motherboard);
}

void GamingComputerBuilder::addRAM()
{
    Ram* ram = new Ram[4];
    ram[0] = Ram("CORSAIR Vengeance", 1600, 8);
    ram[1] = Ram("CORSAIR Vengeance", 1600, 8);
    ram[2] = Ram("CORSAIR Vengeance", 1600, 8);
    ram[3] = Ram("CORSAIR Vengeance", 1600, 8);
    m_computer->setRAM(ram, 4);
    delete[] ram;
}

void GamingComputerBuilder::addHardDrive()
{
    HardDrive** hardDrive = new HardDrive*[3];
    hardDrive[0] = new HardDiscDrive("Western Digital Blue WD5000AAKX", 2000, 7200);
    hardDrive[1] = new HardDiscDrive("Western Digital Blue WD5000AAKX", 2000, 7200);
    hardDrive[2] = new HardDiscDrive("Western Digital Blue WD5000AAKX", 2000, 7200);
    m_computer->setHardDrives(hardDrive, 3);
    delete hardDrive[0];
    delete[] hardDrive;
}

void GamingComputerBuilder::addGraphicsCard()
{
    GraphicsCard* graphicsCard = new GraphicsCard[2];
    graphicsCard[0] = GraphicsCard("nVidia GTX 980 TI", 1100, 1);
    graphicsCard[1] = GraphicsCard("nVidia GTX 980 TI", 1100, 1);
    m_computer->setGraphicsCards(graphicsCard, 2);
    delete[] graphicsCard;
}

void GamingComputerBuilder::addPowerSupply()
{
    PowerSupply powerSupply ("Be Quiet! Power Zone", 650);
    m_computer->setPowerSupply(powerSupply);
}

void GamingComputerBuilder::addCase()
{
    Case computerCase ("Corsair Obsidian 750D Black Aluminum", BaseUnit);
    m_computer->setCase(computerCase);
}

void GamingComputerBuilder::addAdditionalParts()
{
    BluRayDrive dvdDrive("BluRay", 24);
    m_computer->setNumberOfAdditionalParts(1);
    m_computer->addAdditionalPart(dvdDrive);
}
