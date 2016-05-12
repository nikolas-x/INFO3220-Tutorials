#include <math.h>
#include "EuclideanVector.h"

Week9::EuclideanVector::EuclideanVector(unsigned int size)
    : m_size(size)
    , m_elements(new double[size]) {}

Week9::EuclideanVector::EuclideanVector(const std::vector<double> &vector)
    : m_size(vector.size())
    , m_elements(new double[vector.size()])
{
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        m_elements[i] = vector[i];
    }
}

Week9::EuclideanVector::EuclideanVector(const Week9::EuclideanVector &vector)
    : m_size(vector.size())
    , m_elements(new double[vector.size()])
{
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        m_elements[i] = vector[i];
    }
}

Week9::EuclideanVector::~EuclideanVector()
{
    delete[] m_elements;
}

Week9::EuclideanVector &Week9::EuclideanVector::operator=(const Week9::EuclideanVector &vector)
{
    if (m_size != vector.size())
    {
        throw VectorAssignmentException("Incompatible Vector Sizes");
    }

    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        m_elements[i] = vector[i];
    }
    return *this;
}

unsigned int Week9::EuclideanVector::size() const
{
    return m_size;
}

bool Week9::EuclideanVector::operator==(const Week9::EuclideanVector &vector) const
{
    if (m_size != vector.size())
    {
        return false;
    }
    double lowerBound;
    double upperBound;
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        lowerBound = m_elements[i] - 0.01;
        upperBound = m_elements[i] + 0.01;

        if ((vector[i] < lowerBound) || (vector[i] > upperBound))
        {
            return false;
        }
    }
    return true;
}

bool Week9::EuclideanVector::operator!=(const Week9::EuclideanVector &vector) const
{
    return !(operator==(vector));
}

double Week9::EuclideanVector::length() const
{
    double sum = 0;
    for (unsigned int i = 0; i < m_size; ++i)
    {
        sum += m_elements[i] * m_elements[i];
    }
    return sqrt(sum);
}

double Week9::EuclideanVector::dotProduct(const Week9::EuclideanVector &vector) const
{
    if (m_size != vector.size())
    {
        throw VectorArithmeticException("Vectors are not the same size");
    }

    double sum = 0;
    for (unsigned int i = 0; i < m_size; ++i)
    {
        sum += m_elements[i] * vector[i];
    }
    return sum;
}

Week9::EuclideanVector Week9::EuclideanVector::unitVector() const
{
    std::vector<double> elements;
    double l = length();
    for (unsigned int i = 0; i < m_size; ++i)
    {
        elements.push_back(m_elements[i] / l);
    }

    EuclideanVector* ev = new EuclideanVector(elements);
    return *ev;
}

Week9::EuclideanVector Week9::EuclideanVector::operator+(const Week9::EuclideanVector &vector) const
{
    if (m_size != vector.size())
    {
        throw VectorArithmeticException("Vectors are not the same size");
    }

    std::vector<double> elements;
    for (unsigned int i = 0; i < m_size; ++i)
    {
        elements.push_back(m_elements[i] + vector[i]);
    }

    EuclideanVector* ev = new EuclideanVector(elements);
    return *ev;
}

Week9::EuclideanVector Week9::EuclideanVector::operator-(const Week9::EuclideanVector &vector) const
{
    if (m_size != vector.size())
    {
        throw VectorArithmeticException("Vectors are not the same size");
    }

    std::vector<double> elements;
    for (unsigned int i = 0; i < m_size; ++i)
    {
        elements.push_back(m_elements[i] - vector[i]);
    }

    EuclideanVector* ev = new EuclideanVector(elements);
    return *ev;
}

Week9::EuclideanVector &Week9::EuclideanVector::operator+=(const Week9::EuclideanVector &vector)
{
    if (m_size != vector.size())
    {
        throw VectorArithmeticException("Vectors are not the same size");
    }

    for (unsigned int i = 0; i < m_size; ++i)
    {
        m_elements[i] += vector[i];
    }

    return *this;
}

Week9::EuclideanVector &Week9::EuclideanVector::operator-=(const Week9::EuclideanVector &vector)
{
    if (m_size != vector.size())
    {
        throw VectorArithmeticException("Vectors are not the same size");
    }

    for (unsigned int i = 0; i < m_size; ++i)
    {
        m_elements[i] -= vector[i];
    }

    return *this;
}

Week9::EuclideanVector &Week9::EuclideanVector::operator*=(double scalingValue)
{
    for (unsigned int i = 0; i < m_size; ++i)
    {
        m_elements[i] *= scalingValue;
    }

    return *this;
}

Week9::EuclideanVector &Week9::EuclideanVector::operator/=(double scalingValue)
{
    for (unsigned int i = 0; i < m_size; ++i)
    {
        m_elements[i] /= scalingValue;
    }

    return *this;
}

double &Week9::EuclideanVector::operator[](unsigned int index)
{
    if (index >= m_size)
    {
        throw VectorIndexOutOfBoundsException("Index is greater than or equal to the allocated size");
    }

    return m_elements[index];
}

const double &Week9::EuclideanVector::operator[](unsigned int index) const
{
    if (index >= m_size)
    {
        throw VectorIndexOutOfBoundsException("Index is greater than or equal to the allocated size");
    }

    return m_elements[index];
}
