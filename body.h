#ifndef BODY_H
#define BODY_H

// gravitational constant
#define G (6.67428e-11)

// astronomical unit
#define AU (1.4960000e+11)

class Body
{
private:
    // mass of body
    double m_mass;

    // position vector of body
    double m_xPosition;
    double m_yPosition;

    // velocity vector of body
    double m_xVelocity;
    double m_yVelocity;

public:
    Body(double mass,
         double xPosition,
         double yPosition,
         double xVelocity,
         double yVelocity) :
         m_mass(mass),
         m_xPosition(xPosition),
         m_yPosition(yPosition),
         m_xVelocity(xVelocity),
         m_yVelocity(yVelocity) { }

    virtual ~Body() { }

    // get body mass
    double getMass() const { return m_mass; }

    // get position of body
    double getXPosition() const { return m_xPosition; }
    double getYPosition() const { return m_yPosition; }

    // get velocity of body
    double getXVelocity() const { return m_xVelocity; }
    double getYVelocity() const { return m_yVelocity; }

    // get Euclidean distance to other body
    double getDistance(const Body &other) const;

    // add exerted force vector from body "other"
    void addAttraction(const Body &other, double &xForce, double &yForce);

    // update velocity and position by total force for one time step
    void update(double xTotalForce, double yTotalForce, double timestep);
};

#endif // BODY_H
