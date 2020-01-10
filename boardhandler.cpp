#include "boardhandler.h"

BoardHandler::BoardHandler(BoardPtr boardPtr,
                           ShipsListPtr shipsListPtr) :
    boardPtr(boardPtr),
    shipsListPtr(shipsListPtr) {}

BoardHandler::~BoardHandler()
{
    this->boardPtr.reset();
    this->shipsListPtr.reset();
}

void BoardHandler::print() const
{
    //@TODO
}

void BoardHandler::onInputUpdate(const std::string& input)
{
    this->input = input;
}

void BoardHandler::onGameStateUpdate(const game::state& gameState)
{
    //switch(gameState)
    //{
    //    switch(this->input)
    //}
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

