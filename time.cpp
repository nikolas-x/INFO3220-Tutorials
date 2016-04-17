#include "time.h"

Time::Time(int hours, int minutes, int seconds)
    : m_seconds(hours*3600 + minutes*60 + seconds)
{

}

Time::~Time()
{

}

Time::Time(const Time &time) : m_seconds(time.numberOfSeconds())
{

}

Time &Time::operator=(const Time &time)
{
    m_seconds = time.numberOfSeconds();
    return *this;
}

Time Time::operator+(const Time &time) const
{
    int hours = (int)numberOfHours() % 24;
    int minutes = (int)numberOfMinutes() % 60;
    int seconds = (int)numberOfSeconds() % 60;

    int otherHours = (int)time.numberOfHours() % 24;
    int otherMinutes = (int)time.numberOfMinutes() % 60;
    int otherSeconds = (int)time.numberOfSeconds() % 60;

    return Time(hours + otherHours, minutes + otherMinutes, seconds + otherSeconds);

}

Time operator+(const Time &lhs, int numberOfSeconds)
{
    int totalSeconds = lhs.numberOfSeconds() + numberOfSeconds;

    int hours = (int)(totalSeconds / 3600) % 24;
    int minutes = (int)(totalSeconds / 60) % 60;
    int seconds = totalSeconds % 60;

    return Time(hours, minutes, seconds);
}

Time Time::operator-(const Time &time) const
{
    int hours = (int)numberOfHours() % 24;
    int minutes = (int)numberOfMinutes() % 60;
    int seconds = (int)numberOfSeconds() % 60;

    int otherHours = (int)time.numberOfHours() % 24;
    int otherMinutes = (int)time.numberOfMinutes() % 60;
    int otherSeconds = (int)time.numberOfSeconds() % 60;

    return Time(hours - otherHours, minutes - otherMinutes, seconds - otherSeconds);
}

bool Time::operator==(const Time &time)
{
    int hours = (int)numberOfHours() % 24;
    int minutes = (int)numberOfMinutes() % 60;
    int seconds = (int)numberOfSeconds() % 60;

    int otherHours = (int)time.numberOfHours() % 24;
    int otherMinutes = (int)time.numberOfMinutes() % 60;
    int otherSeconds = (int)time.numberOfSeconds() % 60;

    return hours == otherHours && minutes == otherMinutes && seconds == otherSeconds;
}

bool Time::operator!=(const Time &time)
{
    return !(operator==(time));
}

bool Time::operator<(const Time &time)
{
    int hours = (int)numberOfHours() % 24;
    int minutes = (int)numberOfMinutes() % 60;
    int seconds = (int)numberOfSeconds() % 60;

    int otherHours = (int)time.numberOfHours() % 24;
    int otherMinutes = (int)time.numberOfMinutes() % 60;
    int otherSeconds = (int)time.numberOfSeconds() % 60;

    if (operator!=(time))
    {
        if (hours != otherHours)
        {
            return hours < otherHours;
        }
        else if (minutes != otherMinutes)
        {
            return minutes < otherMinutes;
        }
        else if (seconds != otherSeconds)
        {
            return seconds < otherSeconds;
        }
    }

    return false;
}

bool Time::operator>(const Time &time)
{
    return operator!=(time) && !(operator<(time));
}

bool Time::operator<=(const Time &time)
{
    return operator<(time) || operator==(time);
}

bool Time::operator>=(const Time &time)
{
    return operator>(time) || operator==(time);
}

double Time::numberOfHours() const
{
    return m_seconds / 3600.0;
}

double Time::numberOfMinutes() const
{
    return m_seconds / 60.0;
}

int Time::numberOfSeconds() const
{
    return m_seconds;
}

std::string Time::getTimeAsString() const
{
    std::stringstream ss;

    int hours = (int)numberOfHours() % 24;
    int minutes = (int)numberOfMinutes() % 60;
    int seconds = (int)numberOfSeconds() % 60;

    ss << std::string(hours < 10 ? "0" : "") << hours << ":"
       << std::string(minutes < 10 ? "0" : "") << minutes << ":"
       << std::string(seconds < 10 ? "0" : "") << seconds;

    return ss.str();
}
