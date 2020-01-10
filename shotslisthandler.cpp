#include "shotslisthandler.h"

ShotsListHandler::ShotsListHandler(ShotsListPtr shotsListPtr,
                                   ShipsListPtr shipsListPtr) :
    shotsListPtr(shotsListPtr),
    shipsListPtr(shipsListPtr) {}

ShotsListHandler::~ShotsListHandler()
{
    this->shotsListPtr.reset();
    this->shipsListPtr.reset();
}

void ShotsListHandler::onInputUpdate(const std::string& input)
{
    this->input = input;
}

void ShotsListHandler::onGameStateUpdate(const game::state& gameState)
{
    //switch(gameState)
    //{
    //    switch(this->input)
    //}
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

void ShotsListHandler::addShot(const battle::shot& shot)
{
    this->shotsListPtr->push_back(shot);
}
