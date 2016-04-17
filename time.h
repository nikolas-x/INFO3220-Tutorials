#ifndef TIME_H
#define TIME_H

#include <sstream>
#include <string>

class Time
{
public:
    Time(int hours, int minutes, int seconds);

    ~Time();

    Time(const Time &time);

    Time& operator=(const Time &time);
    Time operator+(const Time &time) const;
    Time operator-(const Time &time) const;
    bool operator==(const Time &time);
    bool operator!=(const Time &time);
    bool operator<(const Time &time);
    bool operator>(const Time &time);
    bool operator<=(const Time &time);
    bool operator>=(const Time &time);

    double numberOfHours() const;
    double numberOfMinutes() const;
    int numberOfSeconds() const;

    std::string getTimeAsString() const;

private:
    int m_seconds;
    Time();
};

Time operator+(const Time &lhs, int numberOfSeconds);

#endif // TIME_H
