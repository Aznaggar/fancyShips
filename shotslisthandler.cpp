#include "shotslisthandler.h"

ShotsListHandler::ShotsListHandler(ShotsListPtr shotsListPtr,
                                   ShipsListPtr shipsListPtr,
                                   GameStatePtr gameStatePtr) :
    shotsListPtr(shotsListPtr),
    shipsListPtr(shipsListPtr),
    gameStatePtr(gameStatePtr) {}

ShotsListHandler::~ShotsListHandler()
{
    this->shotsListPtr.reset();
    this->shipsListPtr.reset();
    this->gameStatePtr.reset();
}

void ShotsListHandler::onUpdate(const std::string& input)
{
    //@TODO
}

void ShotsListHandler::print() const
{
    //@TODO
}

const std::list<battle::shot>& ShotsListHandler::getShotsList() const
{
    return *this->shotsListPtr;
}

const std::list<Ship>& ShotsListHandler::getShipsList() const
{
    return *this->shipsListPtr;
}

const game::state& ShotsListHandler::getGameState() const
{
    return *this->gameStatePtr;
}

void ShotsListHandler::addShot(const battle::shot& shot)
{
    this->shotsListPtr->push_back(shot);
}
