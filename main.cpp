#include <iostream>
#include "UserInterface.h"

int main(int argc, char *argv[])
{
    // This is bad! We should use a dynamic_cast here.
    // These will be dicussed in detail later in the semester.
    UserInterface* interface1 = (UserInterface*) UserInterface::getInstance(100, 200);

    std::cout << interface1->getInterfaceHeight() << std::endl;
    std::cout << interface1->getInterfaceWidth() << std::endl;

    // We should not be able to create a second user interface. This will actually be assigned
    // The same interface properties as interface1
    UserInterface* interface2 = (UserInterface*) UserInterface::getInstance(1000, 2000);

    std::cout << interface2->getInterfaceHeight() << std::endl;
    std::cout << interface2->getInterfaceWidth() << std::endl;

    // Should print out the same memory address
    std::cout << interface1 << std::endl;
    std::cout << interface2 << std::endl;

    return 0;
}
