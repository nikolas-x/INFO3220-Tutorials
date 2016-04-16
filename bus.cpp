#include "bus.h"

using namespace vehicle;

Bus::Bus(int numberOfPassengers,
         int topSpeed,
         double kilometresPerLitre,
         bool seatBeltsInstalled,
         bool standingPassengersAllowed,
         int numberOfWheels)
    : MotorVehicle(numberOfPassengers, topSpeed, numberOfWheels, kilometresPerLitre)
    , m_seatBeltsInstalled(seatBeltsInstalled)
    , m_standingPassengersAllowed(standingPassengersAllowed) {}

Bus::Bus(int numberOfPassengers,
         int topSpeed,
         double kilometresPerLitre,
         std::string color,
         bool seatBeltsInstalled,
         bool standingPassengersAllowed,
         int numberOfWheels)
    : MotorVehicle(numberOfPassengers, topSpeed, numberOfWheels, color, kilometresPerLitre)
    , m_seatBeltsInstalled(seatBeltsInstalled)
    , m_standingPassengersAllowed(standingPassengersAllowed) {}

int Bus::getSafetyRating() const
{
    int SafetyRating = 0;

    if (m_seatBeltsInstalled)
    {
        SafetyRating += 3;
    }
    if (!m_standingPassengersAllowed)
    {
        SafetyRating += 2;
    }
    return SafetyRating;
}
