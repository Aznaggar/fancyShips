#include "position.h"

Position::Position() :
    coords(std::make_pair(0, 0)) {}

Position::Position(const std::pair<int, int>& coords) :
    coords(coords) {}

bool Position::isOnBoard(const Board& board) const
{
    const unsigned int endRow = board.getRowsNum();
    const unsigned int endCol = board.getColsNum();
    const std::vector<std::vector<Position>> matrix = board.getMatrix();

    for (unsigned int i = 0; i < endRow; ++i)
    {
        for (unsigned int j = 0; j < endCol; ++j)
        {
            if (*this == matrix[i][j])
            {
                return true;
            }
        }
    }
    return false;
}


void Position::setX(const int x) { this->coords.first = x; }

void Position::setY(const int y) { this->coords.second = y; }

const std::pair<int, int>& Position::getCoords() const
{
  return this->coords;
}

int Position::getX() const { return this->coords.first; }

int Position::getY() const { return this->coords.second; }

bool Position::operator== (const Position &pos) const
{
  if ((this->coords.first == pos.getX()) &&
      (this->coords.second == pos.getY()))
  {
    return true;
  }
  return false;
}

bool Position::operator!= (const Position &pos) const
{
  return !(*this == pos) ? false : true;
}

Position& Position::operator= (const Position &pos)
{
  this->coords = pos.getCoords();
  return *this;
}

Position* Position::operator-> ()
{
  return this;
}
