#include "shiptype.h"

ShipType::ShipType(const std::string& name,
                   const int len) : name(name),
                                    len(len) {}

int ShipType::getLen() const { return this->len; }

const std::string& ShipType::getName() const
{
    return this->name;
}
