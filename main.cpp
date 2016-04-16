#include <iostream>

#include "Bicycle.h"
#include "Bus.h"
#include "Car.h"

using namespace vehicle;

int main(int argc, char* argv[])
{

    Bicycle bicycle1(1, 15);
    Bicycle bicycle2(1, 10, std::string("Blue"));
    Bicycle bicycle3(1, 15, true);
    Bicycle bicycle4(1, 10, std::string("Yellow"), true);
    Bicycle bicycle5(1, 15, true, 3);
    Bicycle bicycle6(1, 10, std::string("Green"), true, 3);

    Bus bus1(1, 75, 10, true, false);
    Bus bus2(1, 75, 10, std::string("Blue"), true, true);
    Bus bus3(1, 75, 10);
    Bus bus4(1, 75, 10, false, true);

    Car car1(1, 75, 10, 4);
    Car car2(1, 75, 10, std::string("Blue"));
    Car car3(1, 75, 10);
    Car car4(1, 75, 10, 6, true, 4);
    Car car5(1, 75, 10, std::string("Green"), 6, true, 4);

    std::cout << bicycle1.getSafetyRating() << std::endl;
    std::cout << bicycle2.getSafetyRating() << std::endl;
    std::cout << bicycle3.getSafetyRating() << std::endl;
    std::cout << bicycle4.getSafetyRating() << std::endl;
    std::cout << bicycle5.getSafetyRating() << std::endl;
    std::cout << bicycle6.getSafetyRating() << std::endl;

    std::cout << bus1.getSafetyRating() << std::endl;
    std::cout << bus2.getSafetyRating() << std::endl;
    std::cout << bus3.getSafetyRating() << std::endl;
    std::cout << bus4.getSafetyRating() << std::endl;

    std::cout << car1.getSafetyRating() << std::endl;
    std::cout << car2.getSafetyRating() << std::endl;
    std::cout << car3.getSafetyRating() << std::endl;
    std::cout << car4.getSafetyRating() << std::endl;
    std::cout << car5.getSafetyRating() << std::endl;

    return 0;
}
