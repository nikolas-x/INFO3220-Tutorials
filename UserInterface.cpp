#include "UserInterface.h"
#include "Singleton.h"

// Add implementation code here


UserInterface *UserInterface::getInstance(int interfaceWidth, int interfaceHeight)
{
    if (s_initialised)
    {
        return (UserInterface*) s_singletonInstance;
    }
    else
    {
        s_singletonInstance = new UserInterface(interfaceWidth, interfaceHeight);
        s_initialised = true;
        return (UserInterface*) s_singletonInstance;
    }
}

UserInterface::UserInterface(int interfaceWidth, int interfaceHeight)
    : Singleton()
    , m_interfaceWidth(interfaceWidth)
    , m_interfaceHeight(interfaceHeight) {}
