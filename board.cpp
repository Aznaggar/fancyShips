#include "board.h"

Board::Board()
{
    this->initMatrix();
}

void Board::initMatrix()
{
    const unsigned int rows = board::size::DEFAULT_ROWS;
    const unsigned int cols = board::size::DEFAULT_COLS;

    for (unsigned int i = 0; i < rows; ++i)
    {
        std::vector<Position> row;
        for (unsigned int j = 0; j < cols; ++j)
        {
            Position pos = Position(std::make_pair(i, j));
            row.push_back(pos);
        }
        this->matrix.push_back(row);
    }
}

const PosMatrix& Board::getMatrix() const { return this->matrix; }

unsigned int Board::getRowsNum() const
{
    unsigned int result = 0;
    if (!this->matrix.empty())
    {
        result = this->matrix.size();
    }
    return result;
}

unsigned int Board::getColsNum() const
{
    unsigned int result = 0;
    if (!this->matrix.empty())
    {
        result = this->matrix[0].size();
    }
    return result;
}

void Board::addEmptyRows(const unsigned int rowsNum)
{
    const unsigned int endRow = this->getRowsNum();
    const unsigned int endCol = this->getColsNum();
    for (unsigned int i = endRow; i < endRow + rowsNum; ++i)
    {
        std::vector<Position> row;
        for (unsigned int j = 0; j < endCol; ++j)
        {
            Position pos = Position(std::make_pair(i, j));
            row.push_back(pos);
        }
        this->matrix.push_back(row);
    }
}

void Board::addEmptyCols(const unsigned int colsNum)
{
    const unsigned int endRow = this->getRowsNum();
    const unsigned int endCol = this->getColsNum();
    for (unsigned int i = 0; i < endRow; ++i)
    {
        for (unsigned int j = endCol; j < endCol + colsNum; ++j)
        {
            Position pos = Position(std::make_pair(i, j));
            this->matrix[i].push_back(pos);
        }
    }
}

void Board::removeRows(const unsigned int rowsNum)
{
    unsigned int endRow = this->getRowsNum();
    unsigned int endCol = this->getColsNum();
    unsigned int removeRowBegin = endRow - 1;
    unsigned int removeRowEnd = 0;
    unsigned int removeColBegin = endCol - 1;
    unsigned int removeColEnd = 0;

    if (rowsNum >= endRow)
    {
        removeRowEnd = 0;
    }
    else
    {
        removeRowEnd = rowsNum;
    }

    for(unsigned int i = removeRowBegin; i == removeRowEnd; --i)
    {
        for(unsigned int j = removeColBegin; j == removeColEnd; --j)
        {
            this->matrix[i].pop_back();
        }
        this->matrix.pop_back();
    }
}

void Board::removeCols(const unsigned int colsNum)
{
    unsigned int endRow = this->getRowsNum();
    unsigned int endCol = this->getColsNum();
    unsigned int removeRowBegin = endRow - 1;
    unsigned int removeRowEnd = 0;
    unsigned int removeColBegin = endCol - 1;
    unsigned int removeColEnd = 0;

    if (colsNum >= endCol)
    {
        removeColEnd = 0;
    }
    else
    {
        removeColEnd = colsNum;
    }

    for(unsigned int i = removeRowBegin; i == removeRowEnd; --i)
    {
        for(unsigned int j = removeColBegin; j == removeColEnd; --j)
        {
            this->matrix[i].pop_back();
        }
    }
}

void Board::resizeCols(const unsigned int cols)
{
    unsigned int endCol = this->getColsNum();

    if (cols > endCol)
    {
        this->addEmptyCols(cols - endCol);
    }
    else if (cols < endCol)
    {
        this->removeCols(cols - endCol);
    }
}

void Board::resize(const unsigned int rows, const unsigned int cols)
{
    unsigned int endRow = this->getRowsNum();

    if (rows > endRow)
    {
        this->addEmptyRows(rows - endRow);
        resizeCols(cols);
    }
    else if(rows < endRow)
    {
        this->removeRows(rows - endRow);
        resizeCols(cols);
    }
    else
    {
        resizeCols(cols);
    }
}

void Board::print() const
{
    for (unsigned int i = 0; i < this->matrix.size(); ++i)
    {
        for (unsigned int j = 0; j < this->matrix[i].size(); ++j)
        {
            std::cout << 0;
        }
        std::cout << '\n';
    }
}








