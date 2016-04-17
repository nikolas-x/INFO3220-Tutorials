#ifndef WATERCOOLING_H
#define WATERCOOLING_H

#include "Part.h"

class WaterCooling : public Part
{
public:

    /**
     * @brief WaterCooling default constructor
     */
    WaterCooling();

    /**
     * @brief WaterCooling constructor
     * @param name description of part
     * @param systemType type of water cooling system (CPU, GPU, etc)
     */
    WaterCooling(const std::string &name, const std::string &systemType);

    /**
     * @brief WaterCooling copy constructor
     * @param waterCooling a WaterCooling object
     */
    WaterCooling(const WaterCooling &waterCooling);

    /**
     * @brief ~WaterCooling destructor
     */
    virtual ~WaterCooling();

    /**
     * @brief getPartInformation constructs the part information for the WaterCooling class
     * @return returns the part information for the WaterCooling class as a std::string
     */
    virtual std::string getPartInformation() const;

private:
    std::string m_systemType;
};

#endif // WATERCOOLING_H
