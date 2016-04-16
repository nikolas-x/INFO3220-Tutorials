#ifndef CAR_H
#define CAR_H

#include "motorvehicle.h"

namespace vehicle {
    class Car : public MotorVehicle
    {
    public:
        Car(int numberOfPassengers,
            int topSpeed,
            double kilometresPerLitre,
            int numberOfAirBags = 2,
            bool abs = true,
            int numberOfWheels = 4);

        Car(int numberOfPassengers,
            int topSpeed,
            double kilometresPerLitre,
            std::string color,
            int numberOfAirBags = 2,
            bool abs = true,
            int numberOfWheels = 4);

        int getSafetyRating() const;

        int getNumberOfAirBags() const
        {
            return m_numberOfAirBags;
        }

        bool abs() const
        {
            return m_abs;
        }

    private:
        bool m_abs;
        int m_numberOfAirBags;
    };
}
#endif // CAR_H
