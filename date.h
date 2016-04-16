#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <string>

namespace Week4
{
    class Date
    {
    public:
        Date(int day, int month, int year);
        ~Date();

        int getDay() const;
        int getMonth() const;
        int getYear() const;

        std::string dateAsString() const;

    private:
        int m_day;
        int m_month;
        int m_year;
    };
}

#endif // DATE_H
