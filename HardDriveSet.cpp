#include "HardDriveSet.h"
#include "PartAllocator.h"

HardDriveSet::HardDriveSet()
    : m_hardDrives(0)
    , m_numberOfHardDrives(-1) {}

HardDriveSet::HardDriveSet(HardDrive **hardDrives, int numberOfHardDrives)
    : Part("Hard Drive Set")
    , m_hardDrives(new HardDrive*[numberOfHardDrives])
    , m_numberOfHardDrives(numberOfHardDrives)
{
    for (int i = 0; i < m_numberOfHardDrives; ++i)
    {
        m_hardDrives[i] = PartAllocator::getHardDrive(hardDrives[i]);
    }
}

HardDriveSet::HardDriveSet(const HardDriveSet &hardDriveSet)
    : Part("Hard Drive Set")
    , m_hardDrives(hardDriveSet.getHardDrives())
    , m_numberOfHardDrives(hardDriveSet.getNumberOfHardDrives()) {}

HardDriveSet::~HardDriveSet()
{
    if (m_hardDrives != 0 && m_numberOfHardDrives != -1)
    {
        /*
        for (int i = 0; i < m_numberOfHardDrives; ++i)
        {
            delete m_hardDrives[i];
        }
        */

        delete[] m_hardDrives;
    }

    m_hardDrives = 0;
    m_numberOfHardDrives = -1;
}

std::string HardDriveSet::getPartInformation() const
{
    std::stringstream ss;
    ss << "Hard Drives: Number Of Drives: "
       << m_numberOfHardDrives;
    for (int i = 0; i < m_numberOfHardDrives; ++i)
    {
        ss << std::endl
           << "Drive "
           << i + 1
           << ": "
           << m_hardDrives[i]->getPartInformation();
    }
    return ss.str();
}

HardDrive **HardDriveSet::getHardDrives() const
{
    return m_hardDrives;
}

int HardDriveSet::getNumberOfHardDrives() const
{
    return m_numberOfHardDrives;
}
