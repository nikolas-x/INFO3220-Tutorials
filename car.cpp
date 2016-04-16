#include "car.h"

using namespace vehicle;

Car::Car(int numberOfPassengers,
         int topSpeed,
         double kilometresPerLitre,
         int numberOfAirBags,
         bool abs,
         int numberOfWheels)
    : MotorVehicle(numberOfPassengers, topSpeed, numberOfWheels,kilometresPerLitre)
    , m_abs(abs)
    , m_numberOfAirBags(numberOfAirBags) {}

Car::Car(int numberOfPassengers,
         int topSpeed,
         double kilometresPerLitre,
         std::string color,
         int numberOfAirBags,
         bool abs,
         int numberOfWheels)
    : MotorVehicle(numberOfPassengers, topSpeed, numberOfWheels, color, kilometresPerLitre)
    , m_abs(abs)
    , m_numberOfAirBags(numberOfAirBags) {}

int Car::getSafetyRating() const
{
    int SafetyRating = 0;
    if (m_numberOfAirBags >= 4)
    {
        SafetyRating += 3;
    }
    else if (m_numberOfAirBags >= 2)
    {
        SafetyRating += 2;
    }
    else if (m_numberOfAirBags > 0)
    {
        SafetyRating += 1;
    }

    if (m_abs)
    {
        SafetyRating += 2;
    }
    return SafetyRating;
}
