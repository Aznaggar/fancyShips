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
