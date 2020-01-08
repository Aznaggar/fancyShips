#include "boardhandler.h"

BoardHandler::BoardHandler(BoardPtr boardPtr,
                           ShipsListPtr shipsListPtr,
                           GameStatePtr gameStatePtr) :
    boardPtr(boardPtr),
    shipsListPtr(shipsListPtr),
    gameStatePtr(gameStatePtr) {}

BoardHandler::~BoardHandler()
{
    this->boardPtr.reset();
    this->shipsListPtr.reset();
    this->gameStatePtr.reset();
}

void BoardHandler::print() const
{
    //@TODO
}

void BoardHandler::onUpdate(const std::string&)
{
    //@TODO
}

const Board& BoardHandler::getBoard() const
{
    return *this->boardPtr;
}

const std::list<Ship>& BoardHandler::getShipsList() const
{
    return *this->shipsListPtr;
}

const game::state& BoardHandler::getGameState() const
{
    return *this->gameStatePtr;
}

void BoardHandler::printEmpty() const
{
    //@TODO
}

void BoardHandler::printNonEmpty() const
{
    //@TODO
}

void BoardHandler::printBattle() const
{
    //@TODO
}

