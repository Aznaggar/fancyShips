#include "ship.h"

Ship::Ship(const ShipType& type,
           const std::vector<Mast>& mastVec,
           const Board& board) :
    type(type),
    mastVec(mastVec)
{
    this->setAdjPosList(board);
}

const ShipType& Ship::getType() const { return this->type; }

const std::vector<Mast>& Ship::getMastVec() const { return this->mastVec; }

const std::list<Position>& Ship::getAdjPosList() const { return this->adjPosList; }

const std::list<Position> Ship::getPosList() const
{
    std::list<Position> posList;

    for(const Mast& mast: this->mastVec)
    {
        Position pos = mast.getPos();
        posList.push_back(pos);
    }

    return posList;
}

const Mast& Ship::getFirstMast() const { return this->mastVec.front(); }

const Mast& Ship::getLastMast() const { return this->mastVec.back(); }

unsigned int Ship::getAdjBoundCoord(const ship::boundoption& option) const
{
    const unsigned int firstMastX = this->getFirstMast().getPos().getX();
    const unsigned int firstMastY = this->getFirstMast().getPos().getY();
    const unsigned int lastMastX = this->getLastMast().getPos().getX();
    const unsigned int lastMastY = this->getLastMast().getPos().getY();

    switch(option)
    {
    case ship::boundoption::UPPER:
        return firstMastX - 1;
    case ship::boundoption::BOTTOM:
        return lastMastX + 1;
    case ship::boundoption::LEFT:
        return firstMastY - 1;
    case ship::boundoption::RIGHT:
        return lastMastY + 1;
    default:
        return 0;
    }
}

const Position Ship::getAdjCornerPos(const ship::corneroption& option) const
{
    const unsigned int upperBoundCoord = this->getAdjBoundCoord(ship::boundoption::UPPER);
    const unsigned int bottomBoundCoord = this->getAdjBoundCoord(ship::boundoption::BOTTOM);
    const unsigned int leftBoundCoord = this->getAdjBoundCoord(ship::boundoption::LEFT);
    const unsigned int rightBoundCoord = this->getAdjBoundCoord(ship::boundoption::RIGHT);

    std::pair<int, int> cornerCoords;
    switch(option)
    {
    case ship::corneroption::UPPER_LEFT:
        cornerCoords = std::make_pair(upperBoundCoord, leftBoundCoord);
    case ship::corneroption::UPPER_RIGHT:
        cornerCoords = std::make_pair(upperBoundCoord, rightBoundCoord);
    case ship::corneroption::BOTTOM_LEFT:
        cornerCoords = std::make_pair(bottomBoundCoord, leftBoundCoord);
    case ship::corneroption::BOTTOM_RIGHT:
        cornerCoords = std::make_pair(bottomBoundCoord, rightBoundCoord);
    default:
        return Position();
    }
    return Position(cornerCoords);
}

bool Ship::isAdjCornerOnBoard(const ship::corneroption& option, const Board& board) const
{
    const Position upperLeftCornerPos = this->getAdjCornerPos(ship::corneroption::UPPER_LEFT);
    const Position upperRightCornerPos = this->getAdjCornerPos(ship::corneroption::UPPER_RIGHT);
    const Position bottomLeftCornerPos = this->getAdjCornerPos(ship::corneroption::BOTTOM_LEFT);
    const Position bottomRightCornerPos = this->getAdjCornerPos(ship::corneroption::BOTTOM_RIGHT);

    switch(option)
    {
    case ship::corneroption::UPPER_LEFT:
        return upperLeftCornerPos.isOnBoard(board);
    case ship::corneroption::UPPER_RIGHT:
        return upperRightCornerPos.isOnBoard(board);
    case ship::corneroption::BOTTOM_LEFT:
        return bottomLeftCornerPos.isOnBoard(board);
    case ship::corneroption::BOTTOM_RIGHT:
        return bottomRightCornerPos.isOnBoard(board);
    default:
        return false;
    }
}

bool Ship::isAdjBoundOnBoard(const ship::boundoption& option, const Board& board) const
{
    const bool upperLeftCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::UPPER_LEFT, board);
    const bool upperRightCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::UPPER_RIGHT, board);
    const bool bottomLeftCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::BOTTOM_LEFT, board);
    const bool bottomRightCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::BOTTOM_RIGHT, board);

    switch(option)
    {
    case ship::boundoption::UPPER:
        return (upperLeftCornerOnBoard || upperRightCornerOnBoard);
    case ship::boundoption::BOTTOM:
        return (bottomLeftCornerOnBoard || bottomRightCornerOnBoard);
    case ship::boundoption::LEFT:
        return (upperLeftCornerOnBoard || bottomLeftCornerOnBoard);
    case ship::boundoption::RIGHT:
        return (upperRightCornerOnBoard || bottomRightCornerOnBoard);
    default:
        return false;
    }
}

void Ship::addAdjBoundCoordPosList(const ship::boundoption& option)
{
    const unsigned int firstMastX = this->getFirstMast().getPos().getX();
    const unsigned int firstMastY = this->getFirstMast().getPos().getY();
    const unsigned int upperBoundCoord = this->getAdjBoundCoord(ship::boundoption::UPPER);
    const unsigned int bottomBoundCoord = this->getAdjBoundCoord(ship::boundoption::BOTTOM);
    const unsigned int leftBoundCoord = this->getAdjBoundCoord(ship::boundoption::LEFT);
    const unsigned int rightBoundCoord = this->getAdjBoundCoord(ship::boundoption::RIGHT);

    if ((option == ship::boundoption::UPPER) ||
        (option == ship::boundoption::BOTTOM))
    {
        unsigned int x = 0;
        unsigned int yIterBegin = firstMastY;
        unsigned int yIterEnd = rightBoundCoord;

        if(option == ship::boundoption::UPPER)
        {
            x = upperBoundCoord;
        }
        else if (option == ship::boundoption::BOTTOM)
        {
            x = bottomBoundCoord;
        }

        for(unsigned int y = yIterBegin; y < yIterEnd; ++y)
        {
            std::pair<int, int> coords = std::make_pair(x, y);
            Position pos = Position(coords);
            this->adjPosList.push_back(pos);
        }
    }
    else
    {
        unsigned int xIterBegin = firstMastX;
        unsigned int xIterEnd = bottomBoundCoord;
        unsigned int y = 0;

        if(option == ship::boundoption::LEFT)
        {
            y = leftBoundCoord;
        }
        else if (option == ship::boundoption::RIGHT)
        {
            y = rightBoundCoord;
        }

        for(unsigned int x = xIterBegin; x < xIterEnd; ++x)
        {
            std::pair<int, int> coords = std::make_pair(x, y);
            Position pos = Position(coords);
            this->adjPosList.push_back(pos);
        }
    }
}

void Ship::addAdjCornerPos(const ship::corneroption& option)
{
    const Position upperLeftCornerPos = this->getAdjCornerPos(ship::corneroption::UPPER_LEFT);
    const Position upperRightCornerPos = this->getAdjCornerPos(ship::corneroption::UPPER_RIGHT);
    const Position bottomLeftCornerPos = this->getAdjCornerPos(ship::corneroption::BOTTOM_LEFT);
    const Position bottomRightCornerPos = this->getAdjCornerPos(ship::corneroption::BOTTOM_RIGHT);

    Position pos;

    switch(option)
    {
    case ship::corneroption::UPPER_LEFT:
        pos = upperLeftCornerPos;
    case ship::corneroption::UPPER_RIGHT:
        pos = upperRightCornerPos;
    case ship::corneroption::BOTTOM_LEFT:
        pos = bottomLeftCornerPos;
    case ship::corneroption::BOTTOM_RIGHT:
        pos = bottomRightCornerPos;
    default:
        pos = Position();
    }

    this->adjPosList.push_back(pos);
}

void Ship::setAdjPosList(const Board& board)
{
    const bool upperLeftCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::UPPER_LEFT, board);
    const bool upperRightCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::UPPER_RIGHT, board);
    const bool bottomLeftCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::BOTTOM_LEFT, board);
    const bool bottomRightCornerOnBoard = this->isAdjCornerOnBoard(ship::corneroption::BOTTOM_RIGHT, board);

    if (upperLeftCornerOnBoard){ this->addAdjCornerPos(ship::corneroption::UPPER_LEFT); }
    if (upperRightCornerOnBoard){ this->addAdjCornerPos(ship::corneroption::UPPER_RIGHT); }
    if (bottomLeftCornerOnBoard){ this->addAdjCornerPos(ship::corneroption::BOTTOM_LEFT); }
    if (bottomRightCornerOnBoard){ this->addAdjCornerPos(ship::corneroption::BOTTOM_RIGHT); }

    const bool upperBoundOnBoard = this->isAdjBoundOnBoard(ship::boundoption::UPPER, board);
    const bool bottomBoundOnBoard = this->isAdjBoundOnBoard(ship::boundoption::UPPER, board);
    const bool leftBoundOnBoard = this->isAdjBoundOnBoard(ship::boundoption::UPPER, board);
    const bool rightBoundOnBoard = this->isAdjBoundOnBoard(ship::boundoption::UPPER, board);

    if (upperBoundOnBoard){ this->addAdjBoundCoordPosList(ship::boundoption::UPPER); }
    if (bottomBoundOnBoard){ this->addAdjBoundCoordPosList(ship::boundoption::BOTTOM); }
    if (leftBoundOnBoard){ this->addAdjBoundCoordPosList(ship::boundoption::LEFT); }
    if (rightBoundOnBoard){ this->addAdjBoundCoordPosList(ship::boundoption::RIGHT); }

    const bool onlyUpperLeftCornerOnBoard = upperLeftCornerOnBoard && !(upperRightCornerOnBoard &&
                                            bottomLeftCornerOnBoard && bottomRightCornerOnBoard);
    const bool onlyUpperRightCornerOnBoard = upperRightCornerOnBoard && !(upperLeftCornerOnBoard &&
                                             bottomLeftCornerOnBoard && bottomRightCornerOnBoard);
    const bool onlyBottomLeftCornerOnBoard = bottomLeftCornerOnBoard && !(upperLeftCornerOnBoard &&
                                             upperRightCornerOnBoard && bottomRightCornerOnBoard);
    const bool onlyBottomRightCornerOnBoard = bottomRightCornerOnBoard && !(upperLeftCornerOnBoard &&
                                              upperRightCornerOnBoard && bottomLeftCornerOnBoard);

    if (onlyUpperLeftCornerOnBoard)
    {
        this->addAdjBoundCoordPosList(ship::boundoption::UPPER);
        this->addAdjBoundCoordPosList(ship::boundoption::LEFT);
    }
    if (onlyUpperRightCornerOnBoard)
    {
        this->addAdjBoundCoordPosList(ship::boundoption::UPPER);
        this->addAdjBoundCoordPosList(ship::boundoption::RIGHT);
    }
    if (onlyBottomLeftCornerOnBoard)
    {
        this->addAdjBoundCoordPosList(ship::boundoption::BOTTOM);
        this->addAdjBoundCoordPosList(ship::boundoption::LEFT);
    }
    if (onlyBottomRightCornerOnBoard)
    {
        this->addAdjBoundCoordPosList(ship::boundoption::BOTTOM);
        this->addAdjBoundCoordPosList(ship::boundoption::RIGHT);
    }
}

bool Ship::isOnBoard(const Board& board) const
{
    bool result = false;
    const Mast firstMast = this->getFirstMast();
    const Mast lastMast = this->getLastMast();

    if (firstMast.isOnBoard(board) && lastMast.isOnBoard(board))
    {
        result = true;
    }

    return result;
}
