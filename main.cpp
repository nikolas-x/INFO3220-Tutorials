#include "Computer.h"
#include "ComputerBuilder.h"
#include "GamingComputerBuilder.h"
#include "OfficeComputerBuilder.h"
#include "ServerBuilder.h"

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

bool createBuilderTest()
{
    ComputerBuilder *builder = new OfficeComputerBuilder();

    builder->createComputer();

    Computer *computer = builder->getResult();

    bool success = (2 == computer->getRamSet().getNumberOfRamSticks())
            && (1 == computer->getHardDriveSet().getNumberOfHardDrives());

    delete builder;
    delete computer;

    return success;
}

bool buildOfficeComputerTest1()
{
    ComputerBuilder *builder = new OfficeComputerBuilder();

    builder->createComputer();

    Computer *computer = builder->getResult();

    delete builder;

    std::string actual = computer->getComputerSpecifications();

    std::string expected = "Office Computer\n";
    expected += "CPU: Intel Celeron G1610 Ivy Bridge Dual-Core, Clock Speed: 2.6 Ghz, Socket: LGA 1155\n";
    expected += "Motherboard: ASUS P8H61-M LE/CSM R2.0, Socket: LGA 1155\n";
    expected += "No. of Ram Slots: 2, No. of Graphics Cards Permitted: 1\n";
    expected += "Ram: Number Of Sticks: 2\n";
    expected += "Slot 1: CORSAIR Vengeance, Frequency: 1600 Mhz, Size: 4 GB\n";
    expected += "Slot 2: CORSAIR Vengeance, Frequency: 1600 Mhz, Size: 4 GB\n";
    expected += "Hard Drives: Number Of Drives: 1\n";
    expected += "Drive 1: Western Digital Blue WD5000AAKX, Size: 500 GB, 7200 RPM\n";
    expected += "Graphics Cards: Number Of Cards: 1\n";
    expected += "Slot 1: On board graphics, Frequency: 650 Mhz, Size: 1 GB\n";
    expected += "Case: Corsair Obsidian 750D Black Aluminum, Case Type: BaseUnit\n";
    expected += "Power Supply: Be Quiet! Power Zone, Maximum Power: 650 Watts\n";
    expected += "Additional Parts\n";
    expected += "DVD Drive: ASUS 24X DVD Burner, Read Speed: 24X";

    delete computer;

    return actual == expected;
}

bool buildOfficeComputerTest2()
{
    ComputerBuilder *builder = new OfficeComputerBuilder();

    builder->createComputer();
    Computer *computer1 = builder->getResult();

    builder->createComputer();
    Computer *computer2 = builder->getResult();

    builder->createComputer();
    Computer *computer3 = builder->getResult();

    std::string actual1 = computer1->getComputerSpecifications();
    std::string actual2 = computer2->getComputerSpecifications();
    std::string actual3 = computer3->getComputerSpecifications();

    std::string expected = "Office Computer\n";
    expected += "CPU: Intel Celeron G1610 Ivy Bridge Dual-Core, Clock Speed: 2.6 Ghz, Socket: LGA 1155\n";
    expected += "Motherboard: ASUS P8H61-M LE/CSM R2.0, Socket: LGA 1155\n";
    expected += "No. of Ram Slots: 2, No. of Graphics Cards Permitted: 1\n";
    expected += "Ram: Number Of Sticks: 2\n";
    expected += "Slot 1: CORSAIR Vengeance, Frequency: 1600 Mhz, Size: 4 GB\n";
    expected += "Slot 2: CORSAIR Vengeance, Frequency: 1600 Mhz, Size: 4 GB\n";
    expected += "Hard Drives: Number Of Drives: 1\n";
    expected += "Drive 1: Western Digital Blue WD5000AAKX, Size: 500 GB, 7200 RPM\n";
    expected += "Graphics Cards: Number Of Cards: 1\n";
    expected += "Slot 1: On board graphics, Frequency: 650 Mhz, Size: 1 GB\n";
    expected += "Case: Corsair Obsidian 750D Black Aluminum, Case Type: BaseUnit\n";
    expected += "Power Supply: Be Quiet! Power Zone, Maximum Power: 650 Watts\n";
    expected += "Additional Parts\n";
    expected += "DVD Drive: ASUS 24X DVD Burner, Read Speed: 24X";

    delete builder;

    delete computer1;
    delete computer2;
    delete computer3;

    return actual1 == expected && actual2 == expected && actual3 == expected;
}

bool buildOfficeComputerTest3()
{
    ComputerBuilder *builder = new OfficeComputerBuilder();

    builder->createComputer();
    Computer *computer1 = builder->getResult();

    builder->createComputer();
    Computer *computer2 = builder->getResult();

    builder->createComputer();
    Computer *computer3 = builder->getResult();

    delete builder;

    std::string actual1 = computer1->getComputerSpecifications();
    std::string actual2 = computer2->getComputerSpecifications();
    std::string actual3 = computer3->getComputerSpecifications();

    delete computer1;
    delete computer2;
    delete computer3;

    std::string expected = "Office Computer\n";
    expected += "CPU: Intel Celeron G1610 Ivy Bridge Dual-Core, Clock Speed: 2.6 Ghz, Socket: LGA 1155\n";
    expected += "Motherboard: ASUS P8H61-M LE/CSM R2.0, Socket: LGA 1155\n";
    expected += "No. of Ram Slots: 2, No. of Graphics Cards Permitted: 1\n";
    expected += "Ram: Number Of Sticks: 2\n";
    expected += "Slot 1: CORSAIR Vengeance, Frequency: 1600 Mhz, Size: 4 GB\n";
    expected += "Slot 2: CORSAIR Vengeance, Frequency: 1600 Mhz, Size: 4 GB\n";
    expected += "Hard Drives: Number Of Drives: 1\n";
    expected += "Drive 1: Western Digital Blue WD5000AAKX, Size: 500 GB, 7200 RPM\n";
    expected += "Graphics Cards: Number Of Cards: 1\n";
    expected += "Slot 1: On board graphics, Frequency: 650 Mhz, Size: 1 GB\n";
    expected += "Case: Corsair Obsidian 750D Black Aluminum, Case Type: BaseUnit\n";
    expected += "Power Supply: Be Quiet! Power Zone, Maximum Power: 650 Watts\n";
    expected += "Additional Parts\n";
    expected += "DVD Drive: ASUS 24X DVD Burner, Read Speed: 24X";

    return actual1 == expected && actual2 == expected && actual3 == expected;
}

bool buildServerTest1()
{
    ComputerBuilder *builder = new ServerBuilder();

    builder->createComputer();

    Computer *computer = builder->getResult();

    Ram* ram = computer->getRamSet().getRamSticks();

    int amountOfRam = 0;

    for (int i = 0; i < computer->getRamSet().getNumberOfRamSticks(); ++i)
    {
        amountOfRam += ram[i].getRamSize();
    }

    if (256 == amountOfRam)
    {
        HardDrive** drives = computer->getHardDriveSet().getHardDrives();

        int amountOfHardDriveSpace = 0;

        for (int i = 0; i < computer->getHardDriveSet().getNumberOfHardDrives(); ++i)
        {
            amountOfHardDriveSpace += drives[i]->getHardDriveSize();
        }

        if (13440 == amountOfHardDriveSpace)
        {
            delete builder;
            delete computer;

            return true;
        }
    }

    delete builder;
    delete computer;

    return false;
}

bool buildServerTest2()
{
    ComputerBuilder *builder = new ServerBuilder();

    builder->createComputer();
    Computer *computer1 = builder->getResult();

    builder->createComputer();
    Computer *computer2 = builder->getResult();

    builder->createComputer();
    Computer *computer3 = builder->getResult();

    std::string actual1 = computer1->getComputerSpecifications();
    std::string actual2 = computer2->getComputerSpecifications();
    std::string actual3 = computer3->getComputerSpecifications();

    std::string expected = "Server\n";
    expected += "CPU: Intel Core i7-4820K Ivy Bridge-E Quad-Core, Clock Speed: 3.7 Ghz, Socket: LGA 1155\n";
    expected += "Motherboard: Intel S2600CP2 SSI EEB Server Motherboard, Socket: LGA 2011\n";
    expected += "No. of Ram Slots: 16, No. of Graphics Cards Permitted: 1\n";
    expected += "Ram: Number Of Sticks: 16\n";
    expected += "Slot 1: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 2: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 3: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 4: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 5: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 6: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 7: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 8: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 9: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 10: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 11: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 12: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 13: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 14: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 15: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 16: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Hard Drives: Number Of Drives: 14\n";
    expected += "Drive 1: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 2: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 3: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 4: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 5: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 6: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 7: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 8: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 9: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 10: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 11: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 12: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 13: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 14: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Graphics Cards: Number Of Cards: 1\n";
    expected += "Slot 1: On board graphics, Frequency: 650 Mhz, Size: 1 GB\n";
    expected += "Case: ARK IPC-4U600 Black 1.2mm SECC Zinc-Coated Steel 4U Rackmount Server Chassis, Case Type: Cabinet\n";
    expected += "Power Supply: Athena Power AP-U2ATX70FEP8 20+4Pin, Maximum Power: 700 Watts\n";
    expected += "Additional Parts\n";
    expected += "CPU: Intel Core i7-4820K Ivy Bridge-E Quad-Core, Clock Speed: 3.7 Ghz, Socket: LGA 1155";

    delete builder;

    delete computer1;
    delete computer2;
    delete computer3;

    return actual1 == expected && actual2 == expected && actual3 == expected;
}

bool buildServerTest3()
{
    ComputerBuilder *builder = new ServerBuilder();

    builder->createComputer();
    Computer *computer1 = builder->getResult();

    builder->createComputer();
    Computer *computer2 = builder->getResult();

    builder->createComputer();
    Computer *computer3 = builder->getResult();

    delete builder;

    std::string actual1 = computer1->getComputerSpecifications();
    std::string actual2 = computer2->getComputerSpecifications();
    std::string actual3 = computer3->getComputerSpecifications();

    delete computer1;
    delete computer2;
    delete computer3;

    std::string expected = "Server\n";
    expected += "CPU: Intel Core i7-4820K Ivy Bridge-E Quad-Core, Clock Speed: 3.7 Ghz, Socket: LGA 1155\n";
    expected += "Motherboard: Intel S2600CP2 SSI EEB Server Motherboard, Socket: LGA 2011\n";
    expected += "No. of Ram Slots: 16, No. of Graphics Cards Permitted: 1\n";
    expected += "Ram: Number Of Sticks: 16\n";
    expected += "Slot 1: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 2: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 3: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 4: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 5: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 6: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 7: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 8: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 9: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 10: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 11: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 12: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 13: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 14: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 15: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Slot 16: Kingston 240-Pin DDR3 Server Memory, Frequency: 1600 Mhz, Size: 16 GB\n";
    expected += "Hard Drives: Number Of Drives: 14\n";
    expected += "Drive 1: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 2: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 3: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 4: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 5: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 6: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 7: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 8: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 9: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 10: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 11: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 12: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 13: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Drive 14: SAMSUNG PM853T Data Center Series, Size: 960 GB\n";
    expected += "Graphics Cards: Number Of Cards: 1\n";
    expected += "Slot 1: On board graphics, Frequency: 650 Mhz, Size: 1 GB\n";
    expected += "Case: ARK IPC-4U600 Black 1.2mm SECC Zinc-Coated Steel 4U Rackmount Server Chassis, Case Type: Cabinet\n";
    expected += "Power Supply: Athena Power AP-U2ATX70FEP8 20+4Pin, Maximum Power: 700 Watts\n";
    expected += "Additional Parts\n";
    expected += "CPU: Intel Core i7-4820K Ivy Bridge-E Quad-Core, Clock Speed: 3.7 Ghz, Socket: LGA 1155";

    return actual1 == expected && actual2 == expected && actual3 == expected;
}

bool buildGamingComputerTest1()
{
    ComputerBuilder *builder = new GamingComputerBuilder();

    builder->createComputer();

    Computer *computer = builder->getResult();

    HardDrive** hardDrives = computer->getHardDriveSet().getHardDrives();

    int hardDriveSpace = 0;

    for (int i = 0; i < computer->getHardDriveSet().getNumberOfHardDrives(); ++i)
    {
        hardDriveSpace += hardDrives[i]->getHardDriveSize();
    }

    if (hardDriveSpace >= 5000)
    {
        delete builder;
        delete computer;

        return true;
    }

    delete builder;
    delete computer;

    return false;
}

bool buildGamingComputerTest2()
{
    ComputerBuilder *builder = new GamingComputerBuilder();

    builder->createComputer();

    Computer *computer = builder->getResult();

    Ram* ram = computer->getRamSet().getRamSticks();

    int amountOfRam = 0;

    for (int i = 0; i < computer->getRamSet().getNumberOfRamSticks(); ++i)
    {
        amountOfRam += ram[i].getRamSize();
    }

    if (amountOfRam >= 16)
    {
        delete builder;
        delete computer;

        return true;
    }

    delete builder;
    delete computer;

    return false;
}

bool buildGamingComputerTest3()
{
    ComputerBuilder *builder = new GamingComputerBuilder();

    builder->createComputer();

    Computer *computer = builder->getResult();

    Part** list = computer->getAdditionalPartsList();

    for (int i = 0; i < computer->getNumberOfAdditionalParts(); ++i)
    {
        Part* part = list[i];
        if (part != 0)
        {
            // tests if Part is a BluRay drive
            if(dynamic_cast<BluRayDrive*>(part))
            {
                delete builder;
                delete computer;

                return true;
            }
        }
    }

    delete builder;
    delete computer;

    return false;
}

int main()
{
    int numberOfTestsFailed = 0;

    // computer tests

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

    // builder tests

    if (!createBuilderTest())
    {
        numberOfTestsFailed++;
    }
    if (!buildOfficeComputerTest1())
    {
        numberOfTestsFailed++;
    }
    if (!buildOfficeComputerTest2())
    {
        numberOfTestsFailed++;
    }
    if (!buildOfficeComputerTest3())
    {
        numberOfTestsFailed++;
    }
    if (!buildServerTest1())
    {
        numberOfTestsFailed++;
    }
    if (!buildServerTest2())
    {
        numberOfTestsFailed++;
    }
    if (!buildServerTest3())
    {
        numberOfTestsFailed++;
    }
    if (!buildGamingComputerTest1())
    {
        numberOfTestsFailed++;
    }
    if (!buildGamingComputerTest2())
    {
        numberOfTestsFailed++;
    }
    if (!buildGamingComputerTest3())
    {
        numberOfTestsFailed++;
    }

    if (0 == numberOfTestsFailed)
    {
        std::cout << "All Tests Passed!" << std::endl;
    }
    else
    {
        std::cout << numberOfTestsFailed << " Tests Failed" << std::endl;
    }
}

