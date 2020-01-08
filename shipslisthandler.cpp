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

void ShipsListHandler::onUpdate(const std::string& input)
{
    //@TODO
}

const std::list<Ship>& ShipsListHandler::getShipsList() const
{
    return *this->shipsListPtr;
}

const std::list<Config>& ShipsListHandler::getConfigsList() const
{
    return *this->configsListPtr;
}

const game::state& ShipsListHandler::getGameState() const
{
    return *this->gameStatePtr;
}

const Board& ShipsListHandler::getBoard() const
{
    return *this->boardPtr;
}

void ShipsListHandler::setShipListPtr(const std::list<Ship>& shipsList)
{
    this->shipsListPtr = std::make_shared<std::list<Ship>>(shipsList);
}

void ShipsListHandler::addShip(const Ship& ship)
{
    this->shipsListPtr->push_back(ship);
}

bool ShipsListHandler::areShipsAdjacent(const Ship& ship, const Ship& otherShip) const
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

bool ShipsListHandler::areShipsColliding(const Ship& ship, const Ship& otherShip) const
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

bool ShipsListHandler::isAdjacent(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : this->getShipsList())
    {
        if (this->areShipsAdjacent(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool ShipsListHandler::isColliding(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : this->getShipsList())
    {
        if (this->areShipsColliding(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool ShipsListHandler::isShipVerified(const Ship& ship) const
{
    //@TODO
    return true;
}

void ShipsListHandler::rearrangeShipsList()
{
    //@TODO
}



