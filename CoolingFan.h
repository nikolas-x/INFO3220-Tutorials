#ifndef COOLINGFAN_H
#define COOLINGFAN_H

#include "Part.h"
#include <stdlib.h>

class CoolingFan : public Part
{
public:

    /**
     * @brief CoolingFan default constructor
     */
    CoolingFan();

    /**
     * @brief CoolingFan constructor
     * @param name description of part
     * @param fanSpeed the Cooling Fan's speed in RPM
     */
    CoolingFan(const std::string &name, int fanSpeed);

    /**
     * @brief CoolingFan copy constructor
     * @param coolingFan a CoolingFan object
     */
    CoolingFan(const CoolingFan &coolingFan);

    /**
     * @brief ~CoolingFan destructor
     */
    virtual ~CoolingFan();

    /**
     * @brief getPartInformation constructs the part information for the CoolingFan class
     * @return returns the part information for the CoolingFan class as a std::string
     */
    virtual std::string getPartInformation() const;

private:
    int m_fanSpeed;
};

#endif // COOLINGFAN_H
