#include "time.h"
#include <complex>
#include <iostream>
#include <string>

bool createTimeObjectTest()
{
    Time time(10, 10, 10);
    return true;
}

bool doublesCompare(double expected, double actual, double tolerance)
{
    return (std::abs(expected - actual) < tolerance);
}

bool numberOfSecondsMinutesAndHoursTest()
{
    Time time(10, 10, 10);
    return (doublesCompare(10.169, time.numberOfHours(), 0.01) && doublesCompare(610.166, time.numberOfMinutes(), 0.01) && 36610 == time.numberOfSeconds());
}

bool toStringTest()
{
    Time time1(10, 10, 10);
    Time time2(1, 0, 25);
    Time time3(0, 0, 0);
    std::string test1 = time1.getTimeAsString();
    std::string test2 = time2.getTimeAsString();
    std::string test3 = time3.getTimeAsString();
    return "10:10:10" == time1.getTimeAsString() && "01:00:25" == time2.getTimeAsString() && "00:00:00" == time3.getTimeAsString();
}

bool copyConstructorTest()
{
    Time time1(10, 10, 10);
    Time time2(time1);
    return "10:10:10" == time1.getTimeAsString() && "10:10:10" == time2.getTimeAsString();
}

bool assignmentOperatorTest()
{
    Time time1(10, 10, 10);
    Time time2 = time1;
    return "10:10:10" == time1.getTimeAsString() && "10:10:10" == time2.getTimeAsString();
}

bool equalityTest()
{
    Time time1(10, 10, 10);
    Time time2(10, 10, 10);
    Time time3(9, 10, 10);
    Time time4(10, 9, 10);
    Time time5(10, 10, 9);

    return time1 == time2 && time1 != time3 && time1 != time4 && time1 != time5;
}

bool additionTest()
{
    Time time1(10, 10, 10);
    Time time2(10, 10, 10);

    Time time3 = time1 + time2;

    Time time4 = time1 + 50;

    return time1 == time2 && time1 != time3 && "20:20:20" == time3.getTimeAsString() && "10:11:00" == time4.getTimeAsString();
}

bool subtractionTest()
{
    Time time1(10, 10, 10);
    Time time2(10, 10, 10);

    Time time3 = time1 - time2;
    return time1 == time2 && time1 != time3 && "00:00:00" == time3.getTimeAsString();
}

bool lessThanTest()
{
    Time time1(11, 10, 10);
    Time time2(10, 20, 60);
    Time time3(10, 20, 60);
    return time2 < time1 && time2 <= time3 && !(time2 < time3);
}

bool greaterThanTest()
{
    Time time1(11, 10, 10);
    Time time2(10, 20, 60);
    Time time3(10, 20, 60);
    return time1 > time2 && time2 >= time3 && !(time2 > time3);
}

int main(int argc, char* argv[])
{
    int numberOfSuccessfulTestsPassed = 10;
    if (!createTimeObjectTest())
    {
        std::cout << "Constructor Test Failed" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!numberOfSecondsMinutesAndHoursTest())
    {
        std::cout << "Number Of Seconds, Number Of Minutes or Number of Hours Methods are incorrect" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!toStringTest())
    {
        std::cout << "To String Method is not working as expected. Check that 2 digits are always returned" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!copyConstructorTest())
    {
        std::cout << "Copy contructor test failed" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!assignmentOperatorTest())
    {
        std::cout << "Assignment operator is not working as expected" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!equalityTest())
    {
        std::cout << "Equality or inequality method is not configured correctly" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!additionTest())
    {
        std::cout << "Time addition test failed, this test also tests the addition method that is a non member method" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!subtractionTest())
    {
        std::cout << "Time subtraction test failed" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!lessThanTest())
    {
        std::cout << "Less than test failed. Check perhaps its your less than or equals to operator" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }
    if (!greaterThanTest())
    {
        std::cout << "Greater than test failed. Check perhaps its your greater than or equals to operator" << std::endl;
        numberOfSuccessfulTestsPassed--;
    }

    std::cout << "Number of Tests Passed: " << numberOfSuccessfulTestsPassed << std::endl;
    if (10 == numberOfSuccessfulTestsPassed)
    {
        std::cout << "Congratulations Task Complete!" << std::endl;
    }
    return 0;
}
