#include "person.h"
#include "student.h"
#include <iostream>

using namespace Week4;

int main(int argc, char* argv[])
{
    Person *student = new Student("Bob", "Down", Date(17,8,1988), "Doctor of Philosophy");
    std::cout << student->getRecord() << std::endl;
    delete student;
    return 0;
}
