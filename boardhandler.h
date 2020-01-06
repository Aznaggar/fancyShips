#pragma once

#include "board.h"

class BoardHandler
{
private:
    BoardPtr boardPtr;
public:
    BoardHandler(BoardPtr);
    virtual ~BoardHandler();
    BoardPtr getBoardPtr() const;
};
