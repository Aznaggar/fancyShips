#include "shiptype.h"

ShipType::ShipType(const std::string& name,
                   const unsigned int len) : name(name), len(len) {}

unsigned int ShipType::getLen() const
{
    return this->len;
}

const std::string& ShipType::getName() const
{
    return this->name;
}

unsigned int shiptype::Functions::getTypeLen(const std::string& name)
{
    if (name == name::DESTROYER)
    {
        return lenght::DESTROYER;
    } else if (name == shiptype::name::SUBMARINE)
    {
        return lenght::SUBMARINE;
    } else if (name == name::CRUISER)
    {
        return lenght::CRUISER;
    } else if (name == name::BATTLESHIP)
    {
        return lenght::BATTLESHIP;
    } else if (name == name::CARRIER)
    {
        return lenght::CARRIER;
    } else
    {
        return 0;
    }
}

unsigned int shiptype::Functions::getArrayIndex(const std::string& name)
{
    if (name == name::DESTROYER)
    {
        return maxnum::arrayindex::DESTROYER;
    } else if (name == shiptype::name::SUBMARINE)
    {
        return maxnum::arrayindex::SUBMARINE;
    } else if (name == name::CRUISER)
    {
        return maxnum::arrayindex::CRUISER;
    } else if (name == name::BATTLESHIP)
    {
        return maxnum::arrayindex::BATTLESHIP;
    } else if (name == name::CARRIER)
    {
        return maxnum::arrayindex::CARRIER;
    } else
    {
        return -1;
    }
}
