#include "boardcontroller.h"

BoardController::BoardController(BoardPtr boardPtr,
                                 ShipsListPtr shipsListPtr) :
    boardPtr(boardPtr),
    shipsListPtr(shipsListPtr) {}

void BoardController::print(const game::state&) const
{

}
