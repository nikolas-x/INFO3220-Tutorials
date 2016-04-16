#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include "Vehicle.h"

namespace vehicle
{
    class MotorVehicle : public Vehicle
    {
    public:
        MotorVehicle(int numberOfPassengers,
            int topSpeed,
            int numberOfWheels,
            double kilometresPerLitre)
            : Vehicle(numberOfPassengers, topSpeed, numberOfWheels)
            , m_kmpl(kilometresPerLitre) {}

        MotorVehicle(int numberOfPassengers,
            int topSpeed,
            int numberOfWheels,
            std::string color,
            double kilometresPerLitre)
            : Vehicle(numberOfPassengers, topSpeed, numberOfWheels, color)
            , m_kmpl(kilometresPerLitre) {}

        virtual ~MotorVehicle() {}

        virtual double getKilometresPerLitre() const
        {
            return m_kmpl;
        }

    protected:
        double m_kmpl;
    };
}

#endif // MOTORVEHICLE_H
