#include "RamSet.h"

RamSet::RamSet() : m_ramSticks(0), m_numberOfRamSticks(-1)
{

}

RamSet::RamSet(Ram* ram, int numberOfRamSticks)
    : Part("Ram Set"), m_ramSticks(new Ram[numberOfRamSticks]), m_numberOfRamSticks(numberOfRamSticks)
{
    for (int i = 0; i < m_numberOfRamSticks; ++i)
    {
        m_ramSticks[i] = Ram(ram[i]);
    }
}

RamSet::RamSet(const RamSet &ramSet)
    : Part("Ram Set"), m_ramSticks(new Ram[ramSet.m_numberOfRamSticks]),
      m_numberOfRamSticks(ramSet.m_numberOfRamSticks)
{
    for (int i = 0; i < m_numberOfRamSticks; ++i)
    {
        m_ramSticks[i] = Ram(ramSet.m_ramSticks[i]);
    }
}

RamSet::~RamSet()
{
    if (m_ramSticks != 0 && -1 != m_numberOfRamSticks)
    {
        delete[] m_ramSticks;
    }
    m_ramSticks = 0;
    m_numberOfRamSticks = -1;
}

std::string RamSet::getPartInformation() const
{
    std::string partInformation("Ram: Number Of Sticks: ");

    char numberOfSticks[5];
    sprintf(numberOfSticks, "%d", m_numberOfRamSticks);

    partInformation += numberOfSticks;

    for (int i = 0; i < m_numberOfRamSticks; ++i)
    {
        char index[5];
        sprintf(index, "%d", i + 1);
        partInformation += "\nSlot " + std::string(index) + ": " + m_ramSticks[i].getPartInformation();
    }

    return partInformation;
}

Ram* RamSet::getRamSticks() const
{
    return m_ramSticks;
}

int RamSet::getNumberOfRamSticks() const
{
    return m_numberOfRamSticks;
}
