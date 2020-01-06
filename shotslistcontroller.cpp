#include "shotslistcontroller.h"

ShotsListController::ShotsListController(ShotsListPtr shotsListPtr,
                                         ShipsListPtr shipsListPtr,
                                         GameStatePtr gameStatePtr) :
    ShotsListHandler(shotsListPtr),
    ShipsListHandler(shipsListPtr),
    GameStateHandler(gameStatePtr) {}

void ShotsListController::print() const
{
    //@TODO
}

void ShotsListController::onUpdate(const std::string& input)
{
    //@TODO
}

ShotsListPtr ShotsListController::getShotsListPtr() const
{
    return ShotsListHandler::getShotsListPtr();
}

void ShotsListController::addShot(const battle::shot& shot)
{
    ShotsListHandler::addShot(shot);
}

ShipsListPtr ShotsListController::getShipsListPtr() const
{
    return ShipsListHandler::getShipsListPtr();
}

GameStatePtr ShotsListController::getGameStatePtr() const
{
    return GameStateHandler::getGameStatePtr();
}
