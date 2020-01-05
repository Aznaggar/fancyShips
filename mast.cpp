#include "mast.h"

Mast::Mast(const Position& pos) :
    pos(pos),
    state(mast::state::FLOATING) {}

void Mast::setState(const mast::state& state) { this->state = state;}

void Mast::setPos(const Position& pos) { this->pos = pos; }

const Position& Mast::getPos() const { return this->pos; }

const mast::state& Mast::getState() const { return this-> state; }

bool Mast::isOnBoard(const Board& board) const
{
    bool result = false;

    if (this->pos.isOnBoard(board))
    {
        result = true;
    }

    return result;
}
