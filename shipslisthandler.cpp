#include "shipslisthandler.h"

ShipsListHandler::ShipsListHandler(ShipsListPtr shipsListPtr) : shipsListPtr(shipsListPtr) {}

ShipsListHandler::~ShipsListHandler() {}

void ShipsListHandler::setShipList(ShipsListPtr shipsListPtr)
{
    this->shipsListPtr = shipsListPtr;
}

ShipsListPtr ShipsListHandler::getShipsList() const
{
    return this->shipsListPtr;
}

void ShipsListHandler::addShip(const Ship& ship)
{
    this->shipsListPtr->push_back(ship);
}
