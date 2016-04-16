#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

namespace Week4
{
    class Student : public Person
    {
    public:
        Student(const std::string& givenName,
                const std::string& surname,
                const Date& date,
                const std::string& degree);

        virtual ~Student();

        virtual std::string getRecord() const;

    private:
        std::string* m_degree;
        mutable int m_recordAccessed;
    };
}

#endif // STUDENT_H
