#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

namespace vehicle
{
    class Vehicle
    {
    public:
        Vehicle(int numberOfPassengers,
            int topSpeed,
            int numberOfWheels,
            std::string color = "red")
            : m_numberOfPassengers(numberOfPassengers)
            , m_topSpeed(topSpeed)
            , m_numberOfWheels(numberOfWheels)
            , m_color(color) {}

        virtual ~Vehicle() {}

        virtual std::string getColor()  const
        {
            return m_color;
        }

        virtual int getTopSpeed() const
        {
            return m_topSpeed;
        }

        virtual int getNumberOfWheels() const
        {
            return m_numberOfWheels;
        }

        virtual int getNumberOfPassengers() const
        {
            return m_numberOfPassengers;
        }

        virtual int getSafetyRating() const = 0;

    protected:
        int m_numberOfPassengers;
        int m_topSpeed;
        int m_numberOfWheels;
        std::string m_color;
    };
}

#endif // VEHICLE_H
