#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <string>

namespace Week4
{
    class Person
    {
    public:
        Person(const std::string& firstName,
               const std::string& surname,
               const Date& dateOfBirth)
            : m_firstName(firstName)
            , m_surname(surname)
            , m_dateOfBirth(dateOfBirth) {}

        virtual ~Person() {}

        const std::string& getFirstName() const;

        const std::string& getSurname() const;

        int getYearOfBirth() const;

        bool isBornInLeapYear() const;

        int getCurrentAge() const;

        virtual std::string getRecord() const = 0;

        void changeFirstName(std::string& firstName);

        void changeSurname(std::string& surname);

    protected:
        std::string m_firstName;
        std::string m_surname;
        Date m_dateOfBirth;
    };
}
#endif // PERSON_H
