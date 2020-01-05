#pragma once
#include <memory>

#include "board.h"
#include "shipslisthandler.h"
#include "iprintable.h"
#include "observer.h"

class BoardController :
        public IPrintable,
        public Observer
{
private:
    BoardPtr boardPtr;
    ShipsListPtr shipsListPtr;

    void printEmpty() const;
    void printNonEmpty() const;
    void printBattle() const;

public:
    BoardController(BoardPtr, ShipsListPtr);

    void print(const game::state&) const;
};

using BoardControllerPtr = std::shared_ptr<BoardController>;
