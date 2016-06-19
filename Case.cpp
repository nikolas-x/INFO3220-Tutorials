#include "Case.h"

Case::Case()
    : Part("Generic Case")
    , m_caseType(BaseUnit)
{

}

Case::Case(const std::string &name, CaseType caseType)
    : Part(name)
    , m_caseType(caseType)
{

}

Case::Case(const Case &computerCase)
    : Part(computerCase)
    , RequiredPart(computerCase)
    , VisitablePart(computerCase)
    , m_caseType(computerCase.m_caseType)
{

}

Case::~Case()
{

}

std::string Case::getPartInformation() const
{
    std::string partInformation ("Case: " + m_name + ", Case Type: ");
    switch (m_caseType)
    {
        case Chassis: return partInformation + "Chassis";
        case Tower: return partInformation + "Tower";
        case SystemUnit: return partInformation + "SystemUnit";
        case Cabinet: return partInformation + "Cabinet";
        case BaseUnit: return partInformation + "BaseUnit";
        default: return partInformation + "Unknown";
    }
}

void Case::accept(Visitor* visitor)
{
    //TODO
}
