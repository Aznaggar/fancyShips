#include "shipslistcontroller.h"

ShipsListController::ShipsListController(ShipsListPtr shipsListPtr,
                                         ConfigsListPtr configsListPtr,
                                         GameStatePtr gameStatePtr,
                                         BoardPtr boardPtr) :
    ShipsListHandler(shipsListPtr),
    ConfigsListHandler(configsListPtr),
    GameStateHandler(gameStatePtr),
    BoardHandler(boardPtr) {}

bool ShipsListController::areShipsAdjacent(const Ship& ship, const Ship& otherShip) const
{
    for (const Position& pos : ship.getPosList())
    {
        for (const Position& adjacentPos : otherShip.getAdjPosList())
        {
            if (pos == adjacentPos)
            {
                return true;
            }
        }
    }
    return false;
}

bool ShipsListController::areShipsColliding(const Ship& ship, const Ship& otherShip) const
{
    for (const Position& pos : ship.getPosList())
    {
        for (const Position& collidingPos : otherShip.getPosList())
        {
            if (pos == collidingPos)
            {
                return true;
            }
        }
    }
    return false;
}

bool ShipsListController::isAdjacent(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : *this->getShipsListPtr())
    {
        if (this->areShipsAdjacent(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool ShipsListController::isColliding(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : *this->getShipsListPtr())
    {
        if (this->areShipsColliding(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool ShipsListController::isShipVerified(const Ship& ship) const
{
    //@TODO
    return true;
}

void ShipsListController::rearrangeShipsList()
{
    //@TODO
}

void ShipsListController::onUpdate(const std::string& input)
{
    //@TODO
}

ShipsListPtr ShipsListController::getShipsListPtr() const
{
    return ShipsListHandler::getShipsListPtr();
}

void ShipsListController::addShip(const Ship& ship)
{
    ShipsListHandler::addShip(ship);
}

void ShipsListController::setShipList(ShipsListPtr shipListPtr)
{
    ShipsListHandler::setShipList(shipListPtr);
}

ConfigsListPtr ShipsListController::getConfigsListPtr() const
{
    return ConfigsListHandler::getConfigsListPtr();
}

GameStatePtr ShipsListController::getGameStatePtr() const
{
    return GameStateHandler::getGameStatePtr();
}

BoardPtr ShipsListController::getBoardPtr() const
{
    return BoardHandler::getBoardPtr();
}
