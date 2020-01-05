#pragma once
#include <iostream>
#include <vector>

#include "position.h"

class Position;

using PosMatrix = std::vector<std::vector<Position>>;

namespace board
{
    namespace size
    {
        const unsigned int DEFAULT_ROWS = 10;
        const unsigned int DEFAULT_COLS = 10;
    }
    namespace sign
    {
        const char EMPTY = '.';
        const char MAST = '$';
        const char HIDDEN = '*';
        const char HIT = 'x';
    }
}

class Board
{
private:
    PosMatrix matrix;
    void initMatrix();

    void addEmptyCols(const unsigned int);
    void addEmptyRows(const unsigned int);

    void removeRows(const unsigned int);
    void removeCols(const unsigned int);

    void resizeCols(const unsigned int);

public:
    Board();
    const PosMatrix& getMatrix() const;

    unsigned int getRowsNum() const;
    unsigned int getColsNum() const;

    void resize(const unsigned int rows, const unsigned int cols);
    void print() const;
};

using BoardPtr = std::shared_ptr<Board>;
