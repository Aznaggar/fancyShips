#include "shipslisthandler.h"

ShipsListHandler::ShipsListHandler(ShipsListPtr shipsListPtr,
                                   ConfigsListPtr configsListPtr,
                                   GameStatePtr gameStatePtr,
                                   BoardPtr boardPtr) :
    shipsListPtr(shipsListPtr),
    configsListPtr(configsListPtr),
    gameStatePtr(gameStatePtr),
    boardPtr(boardPtr) {}

ShipsListHandler::~ShipsListHandler()
{
    this->shipsListPtr.reset();
    this->configsListPtr.reset();
    this->gameStatePtr.reset();
    this->boardPtr.reset();
}

void ShipsListHandler::setShipListPtr(ShipsListPtr shipsListPtr)
{
    this->shipsListPtr = shipsListPtr;
}

ShipsListPtr ShipsListHandler::getShipsListPtr() const
{
    return this->shipsListPtr;
}

void ShipsListHandler::addShip(const Ship& ship)
{
    this->shipsListPtr->push_back(ship);
}

