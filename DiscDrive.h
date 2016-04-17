#ifndef DISCDRIVE_H
#define DISCDRIVE_H

#include "Part.h"
#include <stdlib.h>

class DiscDrive : public Part
{
public:

    /**
     * @brief DiscDrive default constructor
     */
    DiscDrive()
    {

    }

    /**
     * @brief DiscDrive constructor
     * @param name description of part
     * @param readSpeed disc drive read speed
     */
    DiscDrive(const std::string &name, int readSpeed)
        : Part(name), m_readSpeed(readSpeed)
    {

    }

    /**
     * @brief DiscDrive copy constructor
     * @param discDrive a DiscDrive object
     */
    DiscDrive(const DiscDrive &discDrive)
        : Part(discDrive.m_name), m_readSpeed(discDrive.m_readSpeed)
    {

    }

    /**
     * @brief ~DiscDrive destructor
     */
    virtual ~DiscDrive()
    {

    }

    /**
     * @brief getPartInformation constructs the part information for the DiscDrive class
     * @return returns the part information for the DiscDrive class as a std::string
     */
    virtual std::string getPartInformation() const
    {
        char speed[5];
        itoa(m_readSpeed, speed, 10);

        std::string partInformation("Disc Drive: " + m_name + ", Read Speed: " + speed + "X");

        return partInformation;
    }

protected:
    int m_readSpeed;
};

#endif // DISCDRIVE_H
