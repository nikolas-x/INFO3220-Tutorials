#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Singleton.h"

class UserInterface : Singleton
{
public:
    static UserInterface* getInstance(int interfaceWidth, int interfaceHeight);

    int getInterfaceWidth() const
    {
        return m_interfaceWidth;
    }

    int getInterfaceHeight() const
    {
        return m_interfaceHeight;
    }

private:
    UserInterface(int interfaceWidth, int interfaceHeight);
    int m_interfaceWidth;
    int m_interfaceHeight;
};

#endif // USERINTERFACE_H
