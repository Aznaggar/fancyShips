#include "boardcontroller.h"

BoardController::BoardController(BoardPtr boardPtr,
                                 ShipsListPtr shipsListPtr,
                                 GameStatePtr gameStatePtr) :
    BoardHandler(boardPtr),
    ShipsListHandler(shipsListPtr),
    GameStateHandler(gameStatePtr) {}

void BoardController::onUpdate(const std::string& input)
{
    //@TODO
}

void BoardController::print() const
{
    //@TODO
}

BoardPtr BoardController::getBoardPtr() const
{
    return BoardHandler::getBoardPtr();
}

std::list<Ship> BoardController::getShipsListCopy()
{
    return *ShipsListHandler::getShipsListPtr();
}

game::state BoardController::getGameStateCopy()
{
    return *GameStateHandler::getGameStatePtr();
}
