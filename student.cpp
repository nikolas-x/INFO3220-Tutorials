#include "student.h"

using namespace Week4;

Student::Student(const std::string &givenName,
                 const std::string &surname,
                 const Week4::Date &date,
                 const std::string &degree)
    : Person(givenName, surname, date)
    , m_degree(new std::string(degree)) {}

Student::~Student()
{
    delete m_degree;
}

std::string Student::getRecord() const
{
    std::stringstream ss;

    ss << "Name: " << m_firstName << " " << m_surname << std::endl
       << "Date of Birth: " << m_dateOfBirth.dateAsString()
       << "Degree: " << *m_degree << std::endl;

    ++m_recordAccessed;

    return ss.str();
}
