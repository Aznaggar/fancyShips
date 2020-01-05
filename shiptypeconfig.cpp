#include "shipTypeConfig.h"

ShipTypeConfig::ShipTypeConfig(const ShipType& type,
                               const int maxTypeNum) : type(type),
                                                       maxTypeNum(maxTypeNum) {}

void ShipTypeConfig::incrementTypeCounter() { ++this->typeCounter; }

bool ShipTypeConfig::isTypeFullyDeployed() const
{
  bool result = false;
  if (this->typeCounter == this->maxTypeNum)
  {
    result = true;
  }
  return result;
}

const ShipType& ShipTypeConfig::getType() const { return this->type; }
