#include "date.h"

using namespace Week4;

Date::Date(int day, int month, int year)
    : m_day(day)
    , m_month(month)
    , m_year(year) {}

Date::~Date() {}

int Date::getDay() const
{
  return m_day;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getYear() const
{
    return m_year;
}

std::string Date::dateAsString() const
{
    std::stringstream ss;
    ss << std::string(m_day < 10 ? "0" : "") << m_day << "/"
       << std::string(m_month < 10 ? "0" : "") << m_month << "/"
       << m_year << std::endl;

    return ss.str();
}
