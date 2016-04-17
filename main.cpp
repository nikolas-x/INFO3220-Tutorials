#include "Computer.h"
#include <iostream>

bool computerCaseTest()
{
    Computer* computer = new Computer();
    computer->setCase(Case("NZXT Phantom 240", Tower));
    std::string expected = "Case: NZXT Phantom 240, Case Type: Tower";
    std::string actual = std::string(computer->getCase().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerPowerSupplyTest()
{
    Computer* computer = new Computer();
    computer->setPowerSupply(PowerSupply("Cougar CMX1000 V3", 1000));
    std::string expected = "Power Supply: Cougar CMX1000 V3, Maximum Power: 1000 Watts";
    std::string actual = std::string(computer->getPowerSupply().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerMotherboardTest()
{
    Computer* computer = new Computer();
    computer->setMotherboard(Motherboard("ASUS Maximus V EXTREME", "LGA 1155", 4, 2));
    std::string expected = "Motherboard: ASUS Maximus V EXTREME, Socket: LGA 1155\nNo. of Ram Slots: 4, No. of Graphics Cards Permitted: 2";
    std::string actual = std::string(computer->getMotherboard().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerCPUTest()
{
    Computer* computer = new Computer();
    computer->setCPU(CPU("Intel Core i7-3770K Ivy Bridge Quad-Core", 3.5, "LGA 1155"));
    std::string expected = "CPU: Intel Core i7-3770K Ivy Bridge Quad-Core, Clock Speed: 3.5 Ghz, Socket: LGA 1155";
    std::string actual = std::string(computer->getCPU().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerRamTest()
{
    Computer* computer = new Computer();
    Ram* ram = new Ram[4];
    ram[0] = Ram("HyperX FURY", 1866, 8);
    ram[1] = Ram("HyperX FURY", 1866, 8);
    ram[2] = Ram("HyperX FURY", 1866, 8);
    ram[3] = Ram("HyperX FURY", 1866, 8);
    computer->setRAM(ram, 4);
    std::string expected = "Ram: Number Of Sticks: 4\n";
    expected += "Slot 1: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 2: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 3: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 4: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB";
    std::string actual = std::string(computer->getRamSet().getPartInformation());
    delete[] ram;
    delete computer;
    return expected == actual;
}

bool computerRamDeepCopyTest()
{
    Computer* computer = new Computer();
    Ram* ram = new Ram[4];
    ram[0] = Ram("HyperX FURY", 1866, 8);
    ram[1] = Ram("HyperX FURY", 1600, 8);
    ram[2] = Ram("HyperX FURY", 1866, 8);
    ram[3] = Ram("HyperX FURY", 1866, 4);
    computer->setRAM(ram, 4);
    std::string expected = "Ram: Number Of Sticks: 4\n";
    expected += "Slot 1: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 2: HyperX FURY, Frequency: 1600 Mhz, Size: 8 GB\n";
    expected += "Slot 3: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 4: HyperX FURY, Frequency: 1866 Mhz, Size: 4 GB";
    delete[] ram;
    std::string actual = std::string(computer->getRamSet().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerHardDrivesTest()
{
    Computer* computer = new Computer();
    HardDrive** hardDrives = new HardDrive*[3];
    hardDrives[0] = new SolidStateDrive("SAMSUNG 850 EVO-Series MZ-75E1T0B/AM", 1000);
    hardDrives[1] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    hardDrives[2] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    computer->setHardDrives(hardDrives, 3);
    std::string expected = "Hard Drives: Number Of Drives: 3\n";
    expected += "Drive 1: SAMSUNG 850 EVO-Series MZ-75E1T0B/AM, Size: 1000 GB\n";
    expected += "Drive 2: WD BLACK SERIES WD2003FZEX, Size: 2000 GB, 7200 RPM\n";
    expected += "Drive 3: WD BLACK SERIES WD2003FZEX, Size: 2000 GB, 7200 RPM";
    std::string actual = std::string(computer->getHardDriveSet().getPartInformation());
    for (int i = 0; i < 3; ++i)
    {
        delete hardDrives[i];
    }
    delete[] hardDrives;
    delete computer;
    return expected == actual;
}

bool computerHardDrivesDeepCopyTest()
{
    Computer* computer = new Computer();
    HardDrive** hardDrives = new HardDrive*[3];
    hardDrives[0] = new SolidStateDrive("SAMSUNG 850 EVO-Series MZ-75E1T0B/AM", 1000);
    hardDrives[1] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    hardDrives[2] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    computer->setHardDrives(hardDrives, 3);
    std::string expected = "Hard Drives: Number Of Drives: 3\n";
    expected += "Drive 1: SAMSUNG 850 EVO-Series MZ-75E1T0B/AM, Size: 1000 GB\n";
    expected += "Drive 2: WD BLACK SERIES WD2003FZEX, Size: 2000 GB, 7200 RPM\n";
    expected += "Drive 3: WD BLACK SERIES WD2003FZEX, Size: 2000 GB, 7200 RPM";
    for (int i = 0; i < 3; ++i)
    {
        delete hardDrives[i];
    }
    delete[] hardDrives;
    std::string actual = std::string(computer->getHardDriveSet().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerGraphicsCardTest()
{
    Computer* computer = new Computer();
    GraphicsCard* graphicsCards = new GraphicsCard[2];
    graphicsCards[0] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    graphicsCards[1] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    computer->setGraphicsCards(graphicsCards, 2);
    std::string expected = "Graphics Cards: Number Of Cards: 2\n";
    expected += "Slot 1: GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti, Frequency: 1033 Mhz, Size: 2 GB\n";
    expected += "Slot 2: GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti, Frequency: 1033 Mhz, Size: 2 GB";
    std::string actual = std::string(computer->getGraphicsCardSet().getPartInformation());
    delete[] graphicsCards;
    delete computer;
    return expected == actual;
}

bool computerGraphicsCardDeepCopyTest()
{
    Computer* computer = new Computer();
    GraphicsCard* graphicsCards = new GraphicsCard[2];
    graphicsCards[0] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    graphicsCards[1] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    computer->setGraphicsCards(graphicsCards, 2);
    std::string expected = "Graphics Cards: Number Of Cards: 2\n";
    expected += "Slot 1: GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti, Frequency: 1033 Mhz, Size: 2 GB\n";
    expected += "Slot 2: GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti, Frequency: 1033 Mhz, Size: 2 GB";
    delete[] graphicsCards;
    std::string actual = std::string(computer->getGraphicsCardSet().getPartInformation());
    delete computer;
    return expected == actual;
}

bool computerWaterCoolingTest()
{
    Computer* computer = new Computer();
    computer->setNumberOfAdditionalParts(1);
    computer->addAdditionalPart(WaterCooling("CORSAIR Hydro Series H50 120mm", "CPU Block"));
    Part** parts = computer->getAdditionalPartsList();

    std::string expected = "Water Cooler: CORSAIR Hydro Series H50 120mm, Cooling Type: CPU Block";
    std::string actual = std::string(parts[0]->getPartInformation());

    delete computer;
    return expected == actual;
}

bool computerFanTest()
{
    Computer* computer = new Computer();
    computer->setNumberOfAdditionalParts(1);
    computer->addAdditionalPart(CoolingFan("Cooler Master SickleFlow 120 - Sleeve Bearing 120mm", 1600));
    Part** parts = computer->getAdditionalPartsList();

    std::string expected = "Cooling Fan: Cooler Master SickleFlow 120 - Sleeve Bearing 120mm, Speed: 1600 RPM";
    std::string actual = std::string(parts[0]->getPartInformation());

    delete computer;
    return expected == actual;
}

bool computerDVDDriveTest()
{
    Computer* computer = new Computer();
    computer->setNumberOfAdditionalParts(1);
    computer->addAdditionalPart(DVDDrive("ASUS 24X DVD Burner", 16));
    Part** parts = computer->getAdditionalPartsList();

    std::string expected = "DVD Drive: ASUS 24X DVD Burner, Read Speed: 16X";
    std::string actual = std::string(parts[0]->getPartInformation());

    delete computer;
    return expected == actual;
}

bool computerBluRayTest()
{
    Computer* computer = new Computer();
    computer->setNumberOfAdditionalParts(1);
    computer->addAdditionalPart(BluRayDrive("LG Black 12X BD-ROM", 12));
    Part** parts = computer->getAdditionalPartsList();

    std::string expected = "Blu-ray Drive: LG Black 12X BD-ROM, Read Speed: 12X";
    std::string actual = std::string(parts[0]->getPartInformation());

    delete computer;
    return expected == actual;
}

bool buildFullComputerTest()
{
    Computer* computer = new Computer();
    computer->setComputerType("Gaming Computer");
    computer->setCase(Case("NZXT Phantom 240", Tower));
    computer->setPowerSupply(PowerSupply("Cougar CMX1000 V3", 1000));
    computer->setMotherboard(Motherboard("ASUS Maximus V EXTREME", "LGA 1155", 4, 2));
    computer->setCPU(CPU("Intel Core i7-3770K Ivy Bridge Quad-Core", 3.5, "LGA 1155"));

    Ram* ram = new Ram[4];
    ram[0] = Ram("HyperX FURY", 1866, 8);
    ram[1] = Ram("HyperX FURY", 1866, 8);
    ram[2] = Ram("HyperX FURY", 1866, 8);
    ram[3] = Ram("HyperX FURY", 1866, 8);
    computer->setRAM(ram, 4);
    delete[] ram;

    HardDrive** hardDrives = new HardDrive*[3];
    hardDrives[0] = new SolidStateDrive("SAMSUNG 850 EVO-Series MZ-75E1T0B/AM", 1000);
    hardDrives[1] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    hardDrives[2] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    computer->setHardDrives(hardDrives, 3);
    for (int i = 0; i < 3; ++i)
    {
        delete hardDrives[i];
    }
    delete[] hardDrives;

    GraphicsCard* graphicsCards = new GraphicsCard[2];
    graphicsCards[0] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    graphicsCards[1] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    computer->setGraphicsCards(graphicsCards, 2);
    delete[] graphicsCards;

    // We are only going to assign 2. To check the destructor behaves correctly.
    computer->setNumberOfAdditionalParts(3);
    computer->addAdditionalPart(CoolingFan("Cooler Master SickleFlow 120 - Sleeve Bearing 120mm", 1600));
    computer->addAdditionalPart(BluRayDrive("LG Black 12X BD-ROM", 12));

    std::string expected ="Gaming Computer\n";
    expected += "CPU: Intel Core i7-3770K Ivy Bridge Quad-Core, Clock Speed: 3.5 Ghz, Socket: LGA 1155\n";
    expected += "Motherboard: ASUS Maximus V EXTREME, Socket: LGA 1155\nNo. of Ram Slots: 4, No. of Graphics Cards Permitted: 2\n";
    expected += "Ram: Number Of Sticks: 4\n";
    expected += "Slot 1: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 2: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 3: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Slot 4: HyperX FURY, Frequency: 1866 Mhz, Size: 8 GB\n";
    expected += "Hard Drives: Number Of Drives: 3\n";
    expected += "Drive 1: SAMSUNG 850 EVO-Series MZ-75E1T0B/AM, Size: 1000 GB\n";
    expected += "Drive 2: WD BLACK SERIES WD2003FZEX, Size: 2000 GB, 7200 RPM\n";
    expected += "Drive 3: WD BLACK SERIES WD2003FZEX, Size: 2000 GB, 7200 RPM\n";
    expected += "Graphics Cards: Number Of Cards: 2\n";
    expected += "Slot 1: GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti, Frequency: 1033 Mhz, Size: 2 GB\n";
    expected += "Slot 2: GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti, Frequency: 1033 Mhz, Size: 2 GB\n";
    expected += "Case: NZXT Phantom 240, Case Type: Tower\n";
    expected += "Power Supply: Cougar CMX1000 V3, Maximum Power: 1000 Watts\n";
    expected += "Additional Parts\n";
    expected += "Cooling Fan: Cooler Master SickleFlow 120 - Sleeve Bearing 120mm, Speed: 1600 RPM\n";
    expected += "Blu-ray Drive: LG Black 12X BD-ROM, Read Speed: 12X";
    std::string actual = std::string(computer->getComputerSpecifications());

    delete computer;

    return expected == actual;
}

int main()
{
    int numberOfTestsFailed = 0;
    if (!computerCaseTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerPowerSupplyTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerMotherboardTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerCPUTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerRamTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerRamDeepCopyTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerHardDrivesTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerHardDrivesDeepCopyTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerGraphicsCardTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerGraphicsCardDeepCopyTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerWaterCoolingTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerFanTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerDVDDriveTest())
    {
        numberOfTestsFailed++;
    }
    if (!computerBluRayTest())
    {
        numberOfTestsFailed++;
    }
    if (!buildFullComputerTest())
    {
        numberOfTestsFailed++;
    }
    if (0 == numberOfTestsFailed)
    {
        std::cout << "All Tests Passed! Now Move on to creating your Computer Builders" << std::endl;
    }
    else
    {
        std::cout << numberOfTestsFailed << " Tests Failed" << std::endl;
    }
}

