#include "Singleton.h"

bool Singleton::s_initialised = false;
Singleton* Singleton::s_singletonInstance = 0;

Singleton::Singleton()
{
}

Singleton* Singleton::getInstance()
{
    if (s_initialised)
    {
        return s_singletonInstance;
    }
    else
    {
        s_singletonInstance = new Singleton();
        s_initialised = true;
        return s_singletonInstance;
    }
}
