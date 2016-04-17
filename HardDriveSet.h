#ifndef HARDDRIVESET_H
#define HARDDRIVESET_H

#include <sstream>

#include "HardDrive.h"

class HardDriveSet : public Part
{
public:

    /**
     * @brief HardDriveSet default constructor
     */
    HardDriveSet();

    /**
     * @brief HardDriveSet constructor
     * @param hardDrives array of HardDrive pointers
     * @param numberOfHardDrives number of elements in array of HardDrive pointers
     */
    HardDriveSet(HardDrive** hardDrives, int numberOfHardDrives);

    /**
     * @brief HardDriveSet copy constructor
     * @param hardDriveSet instance of the HardDriveSet to perform a deep copy on
     */
    HardDriveSet(const HardDriveSet& hardDriveSet);

    /**
     * @brief ~HardDriveSet destructor
     */
    virtual ~HardDriveSet();

    /**
     * @brief getPartInformation constructs the part information for the HardDriveSet class
     * @return returns the part information for the HardDriveSet class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getHardDrives retrieves an array of HardDrive pointers
     * @return an array of HardDrive pointers
     */
    HardDrive** getHardDrives() const;

    /**
     * @brief getNumberOfHardDrives retrieves number of elements in array of HardDrive pointers
     * @return the number of elements in the HardDrive pointer array
     */
    int getNumberOfHardDrives() const;

private:
    HardDrive** m_hardDrives;
    int m_numberOfHardDrives;
};

#endif // HARDDRIVESET_H
