#include <cmath>
#include "body.h"

// get Euclidean distance to other body
double Body::getDistance(const Body &other) const
{
    double xDelta = other.getXPosition() - m_xPosition;
    double yDelta = other.getYPosition() - m_yPosition;
    double distance =  sqrt(xDelta * xDelta + yDelta * yDelta);
    return distance;
}

// add exerted force vector from body "other"
void Body::addAttraction(const Body &other, double &xForce, double &yForce)
{
    double distance = getDistance(other);
    double xDelta = other.getXPosition() - m_xPosition;
    double yDelta = other.getYPosition() - m_yPosition;
    double theta = atan2(yDelta, xDelta);
    double force = G * m_mass * other.getMass() / (distance * distance);
    xForce += force * cos(theta);
    yForce += force * sin(theta);
}

// update velocity and position by an acceleration for one time step
void Body::update(double xTotalForce, double yTotalForce, double timestep)
{
    // calculate acceleration
    double xAccel = xTotalForce / m_mass;
    double yAccel = yTotalForce / m_mass;

    // integrate acceleration
    m_xVelocity += xAccel * timestep;
    m_yVelocity += yAccel * timestep;

    // integrate velocity
    m_xPosition += m_xVelocity * timestep;
    m_yPosition += m_yVelocity * timestep;
}
