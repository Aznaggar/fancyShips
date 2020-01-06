#pragma once
#include <iostream>
#include <vector>
#include <list>

#include "mast.h"
#include "position.h"
#include "shipType.h"

namespace game
{
    namespace ship
    {
        namespace dir
        {
            const char VERT = 'v';
            const char HOR = 'h';
        }
        enum class boundoption
        {
            UPPER,
            BOTTOM,
            LEFT,
            RIGHT
        };
        enum class corneroption
        {
            UPPER_LEFT,
            UPPER_RIGHT,
            BOTTOM_LEFT,
            BOTTOM_RIGHT
        };
    }
}

using namespace game;

class Ship
{
private:
    ShipType type;
    std::vector<Mast> mastVec;
    std::list<Position> adjPosList;

    const Mast& getFirstMast() const;
    const Mast& getLastMast() const;

    unsigned int getAdjBoundCoord(const ship::boundoption&) const;
    const Position getAdjCornerPos(const ship::corneroption&) const;

    bool isAdjCornerOnBoard(const ship::corneroption&, const Board&) const;
    bool isAdjBoundOnBoard(const ship::boundoption&, const Board&) const;

    void addAdjBoundCoordPosList(const ship::boundoption&);
    void addAdjCornerPos(const ship::corneroption&);

    void setAdjPosList(const Board&);

public:
    Ship(const ShipType&,
         const std::vector<Mast>&,
         const Board&);

    const ShipType& getType() const;
    const std::vector<Mast>& getMastVec() const;
    const std::list<Position> getPosList() const;
    const std::list<Position>& getAdjPosList() const;

    bool isOnBoard(const Board&) const;
};
