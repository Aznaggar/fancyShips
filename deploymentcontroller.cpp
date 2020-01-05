#include "deploymentcontroller.h"

DeploymentController::DeploymentController(ShipsListPtr shipsListPtr,
                                           ConfigsListPtr configsListPtr,
                                           BoardPtr boardPtr) :
    ShipsListHandler(shipsListPtr),
    ConfigsListHandler(configsListPtr),
    boardPtr(boardPtr) {}

bool DeploymentController::areShipsAdjacent(const Ship& ship, const Ship& otherShip) const
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

bool DeploymentController::areShipsColliding(const Ship& ship, const Ship& otherShip) const
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

bool DeploymentController::isAdjacent(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : *ShipsListHandler::getShipsList())
    {
        if (this->areShipsAdjacent(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool DeploymentController::isColliding(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : *ShipsListHandler::getShipsList())
    {
        if (this->areShipsColliding(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool DeploymentController::isShipVerified(const Ship& ship) const
{
    std::cout << ship.getType().getLen();
    //@TODO
    return true;
}

void DeploymentController::rearrangeShipsList()
{
    //@TODO
}
