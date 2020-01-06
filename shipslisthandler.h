#pragma once

#include <list>

#include "ship.h"

using ShipsListPtr = std::shared_ptr<std::list<Ship>>;

class ShipsListHandler
{
private:
  ShipsListPtr shipsListPtr;
public:
  ShipsListHandler(ShipsListPtr);
  virtual ~ShipsListHandler();

  void setShipList(ShipsListPtr);
  ShipsListPtr getShipsListPtr() const;

  void addShip(const Ship& ship);
};
