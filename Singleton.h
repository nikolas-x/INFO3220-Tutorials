#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    static Singleton* getInstance();
protected:
    Singleton();
    static bool s_initialised;
    static Singleton* s_singletonInstance;
};

#endif // SINGLETON_H
