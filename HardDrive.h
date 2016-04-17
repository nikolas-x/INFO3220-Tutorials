#ifndef HARDDRIVE_H
#define HARDDRIVE_H

#include "Part.h"
#include <stdlib.h>

class HardDrive : public Part
{
public:

    /**
     * @brief HardDrive default constructor
     */
    HardDrive()
    {

    }

    /**
     * @brief HardDrive constructor
     * @param name description of part
     * @param size hard drive size (GB)
     */
    HardDrive(const std::string &name, int size)
        : Part(name), m_size(size)
    {

    }

    /**
     * @brief HardDrive copy constructor
     * @param hardDrive a HardDrive object
     */
    HardDrive(const HardDrive &hardDrive)
        : Part(hardDrive.m_name), m_size(hardDrive.m_size)
    {

    }

    /**
     * @brief ~HardDrive destructor
     */
    virtual ~HardDrive()
    {

    }

    /**
     * @brief getPartInformation constructs the part information for the HardDrive class
     * @return returns the part information for the HardDrive class as a std::string
     */
    virtual std::string getPartInformation() const
    {
        char size[5];
        itoa(m_size, size, 10);

        std::string partInformation(m_name + ", Size: " + size + " GB");

        return partInformation;
    }

    /**
     * @brief getHardDriveSize retrieves the hard drive size
     * @return returns the hard drive size
     */
    virtual int getHardDriveSize()
    {
        return m_size;
    }

protected:
    int m_size;
};

#endif // HARDDRIVE_H
