#pragma once
#include <iostream>
#include <vector>

#include "position.h"

class Position;

using PosMatrix = std::vector<std::vector<Position>>;

namespace game
{
    namespace board
    {
        namespace size
        {
            const unsigned int DEFAULT_ROWS = 10;
            const unsigned int DEFAULT_COLS = 10;
        }
    }
}

using namespace game;

class Board
{
private:
    PosMatrix matrix;
    void initMatrix();

    void addCols(const unsigned int);
    void addRows(const unsigned int);

    void removeRows(const unsigned int);
    void removeCols(const unsigned int);

    void resizeCols(const unsigned int);

public:
    Board();
    const PosMatrix& getMatrix() const;

    unsigned int getRowsNum() const;
    unsigned int getColsNum() const;

    void resize(const unsigned int rows, const unsigned int cols);
};

using BoardPtr = std::shared_ptr<Board>;
