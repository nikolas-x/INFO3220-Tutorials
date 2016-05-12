#ifndef COMPUTER_H
#define COMPUTER_H

#include "ComputerPlan.h"
#include "PartAllocator.h"

class Computer : public ComputerPlan
{
public:

    /**
     * @brief Computer default constructor
     */
    Computer();

    /**
     * @brief ~Computer destructor
     */
    virtual ~Computer();

    // Getters

    /**
     * @brief getComputerType retrieves the computer's type
     * @return the computer's type as std::string
     */
    virtual const std::string& getComputerType() const;

    /**
     * @brief getCPU retrieves the computer's cpu information
     * @return the computer's CPU
     */
    virtual const CPU& getCPU() const;

    /**
     * @brief getMotherboard retrieves the computer's motherboard information
     * @return the computer's Motherboard
     */
    virtual const Motherboard& getMotherboard() const;

    /**
     * @brief getRamSet retrieves the computer's ram set information
     * @return the computer's RamSet
     */
    virtual const RamSet& getRamSet() const;

    /**
     * @brief getHardDriveSet retrieves the computer's hard drive set information
     * @return the computer's HardDriveSet
     */
    virtual const HardDriveSet& getHardDriveSet() const;

    /**
     * @brief getGraphicsCardSet retrieves the computer's graphics card set information
     * @return the computer's GraphicsCardSet
     */
    virtual const GraphicsCardSet& getGraphicsCardSet() const;

    /**
     * @brief getPowerSupply retrieves the computer's PSU information
     * @return the computer's PowerSupply
     */
    virtual const PowerSupply& getPowerSupply() const;

    /**
     * @brief getCase retrieves the computer's case information
     * @return the computer's Case
     */
    virtual const Case& getCase() const;

    /**
     * @brief getAdditionalPartsList retrieves the computer's optional part information
     * @return the computer's additional part information
     */
    virtual Part** getAdditionalPartsList() const;

    /**
     * @brief getNumberOfAdditionalParts retrieves the number of optional parts included in the computer
     * @return the number of additional parts included
     */
    virtual int getNumberOfAdditionalParts() const;

    /**
     * @brief getComputerSpecifications retrieves the computers specification
     * @return as a std::string the computers specifications
     */
    virtual std::string getComputerSpecifications() const;

    // Setters

    /**
     * @brief setComputerType setter method for computerType
     * @param computerType computer's type as std::string
     */
    virtual void setComputerType(const std::string &computerType);

    /**
     * @brief setCPU setter method for CPU
     * @param cpu computer's CPU
     */
    virtual void setCPU(const CPU &cpu);

    /**
     * @brief setMotherboard setter method for Motherboard
     * @param motherboard computer's Motherboard
     */
    virtual void setMotherboard(const Motherboard &motherboard);

    /**
     * @brief setRAM setter method for RamSet
     * @param ram list of Ram
     * @param numberOfRamSticks number of items in Ram array
     */
    virtual void setRAM(Ram* ram, int numberOfRamSticks);

    /**
     * @brief setHardDrives setter method for HardDriveSet
     * @param hardDrive list of HardDrive pointers
     * @param numberOfHardDrives number of items in HardDrive array
     */
    virtual void setHardDrives(HardDrive** hardDrive, int numberOfHardDrives);

    /**
     * @brief setGraphicsCards setter method for GraphicsCardSet
     * @param graphicsCard list of GraphicsCard
     * @param numberOfGraphicsCard number of items in GraphicsCard array
     */
    virtual void setGraphicsCards(GraphicsCard* graphicsCard, int numberOfGraphicsCard);

    /**
     * @brief setPowerSupply setter method for PowerSupply
     * @param powerSupply computer's PowerSupply
     */
    virtual void setPowerSupply(const PowerSupply &powerSupply);

    /**
     * @brief setCase setter method for Case
     * @param computerCase computer's Case
     */
    virtual void setCase(const Case &computerCase);

    /**
     * @brief setNumberOfAdditionalParts sets the number of additional parts permitted for computer
     * @param numberOfAdditionalParts the number of additional parts permitted for computer
     */
    virtual void setNumberOfAdditionalParts(int numberOfAdditionalParts);

    /**
     * @brief addAdditionalPart adds one new additional Part to computer
     * @param part additional Part to add to computer
     */
    virtual void addAdditionalPart(const Part &part);

protected:

    enum ComputerPartID
    {
        CPUID,
        MotherboardID,
        RamSetID,
        HardDriveSetID,
        GraphicsCardSetID,
        CaseID,
        PowerSupplyID
    };

    std::string m_computerType;

    Part** m_requiredParts;
    const static int numberOfRequiredParts = 7;

    Part** m_additionalParts;
    int m_numberOfAdditionalParts;
    int m_numberOfAssignedAdditionalParts;
};

#endif // COMPUTER_H
