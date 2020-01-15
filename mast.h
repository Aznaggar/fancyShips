#pragma once

#include <memory>

#include "position.h"
#include "board.h"
namespace game
{
    namespace mast
    {
        enum class state
        {
        FLOATING,
        SINKING
        };
    }
}

using namespace game;

class Mast
{
private:
    Position pos;
    mast::state state;
public:
    Mast(const Position&);
    void setState(const mast::state&);
    void setPos(const Position&);

    const Position& getPos() const;
    const mast::state& getState() const;

    bool isOnBoard(const Board&) const;
};
