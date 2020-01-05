#pragma once
#include <utility>
#include <memory>

#include "board.h"

class Board;

class Position
{
private:
    std::pair<int, int> coords;
    void setX(const int);
    void setY(const int);
public:
    Position();
    Position(const std::pair<int, int>&);

    const std::pair<int, int>& getCoords() const;

    int getX() const;
    int getY() const;

    bool isOnBoard(const Board& board) const;

    bool operator== (const Position&) const;
    bool operator!= (const Position&) const;
    Position& operator= (const Position&);
    Position* operator-> ();
};
