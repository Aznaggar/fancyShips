#include "shipslisthandler.h"

ShipsListHandler::ShipsListHandler(ShipsListPtr shipsListPtr,
                                   BoardPtr boardPtr) :
    shipsListPtr(shipsListPtr),
    boardPtr(boardPtr)
{
    this->initShipTypeMaxNumsArray();
}

ShipsListHandler::~ShipsListHandler()
{
    this->shipsListPtr.reset();
    this->boardPtr.reset();
}

/////////////////////////////////
// overriden observers methods //
/////////////////////////////////
void ShipsListHandler::onInputUpdate(const std::string& input)
{
    this->input = input;
}

void ShipsListHandler::onGameStateUpdate(const game::state& gameState)
{
    const bool noneMaxNumSet = this->noneMaxNumSet();
    const bool onlyFirstMaxNumSet = this->onlyFirstMaxNumSet();
    const bool onlyTwoFirstMaxNumSet = this->onlyTwoFirstMaxNumSet();
    const bool onlyThreeFirstMaxNumSet = this->onlyThreeFirstMaxNumSet();
    const bool onlyFourFirstMaxNumSet = this->onlyFourFirstMaxNumSet();

    switch (gameState)
    {
    case game::state::CONFIG:
        if (noneMaxNumSet)
        {
            this->setShipTypeMaxNum(name::DESTROYER);
        }
        else if (onlyFirstMaxNumSet)
        {
            this->setShipTypeMaxNum(name::SUBMARINE);
        }
        else if (onlyTwoFirstMaxNumSet)
        {
            this->setShipTypeMaxNum(name::CRUISER);
        }
        else if (onlyThreeFirstMaxNumSet)
        {
            this->setShipTypeMaxNum(name::BATTLESHIP);
        }
        else if (onlyFourFirstMaxNumSet)
        {
            this->setShipTypeMaxNum(name::CARRIER);
        }
        break;
    case game::state::DEPLOYMENT:

        break;
    case game::state::BATTLE:

        break;
    case game::state::END:

        break;
    default:
        break;
    }
}

/////////////
// getters //
/////////////
const std::list<Ship>& ShipsListHandler::getShipsList() const
{
    return *this->shipsListPtr;
}

const Board& ShipsListHandler::getBoard() const
{
    return *this->boardPtr;
}

bool ShipsListHandler::inputEquals(const std::string& command)
{
    bool result = false;
    if (this->input == command)
    {
        result = true;
    }
    return result;
}

/////////////
// setters //
/////////////
void ShipsListHandler::setShipTypeMaxNum(const std::string& name)
{
    const unsigned int inputLen = std::stoul(this->input);
    const unsigned int typeLen = shiptype::Functions::getTypeLen(name);
    const unsigned int maxNumTypeIndex = shiptype::Functions::getArrayIndex(name);

    if (inputLen <= typeLen)
    {
        this->shipTypeMaxNumsArray[maxNumTypeIndex] = inputLen;
    }
}

void ShipsListHandler::setShipListPtr(const std::list<Ship>& shipsList)
{
    this->shipsListPtr = std::make_shared<std::list<Ship>>(shipsList);
}

void ShipsListHandler::addShip(const Ship& ship)
{
    this->shipsListPtr->push_back(ship);
}

////////////
// config //
////////////
void ShipsListHandler::initShipTypeMaxNumsArray()
{
    for (unsigned int& shipTypeMaxNum : this->shipTypeMaxNumsArray)
    {
        shipTypeMaxNum = 0;
    }
}

unsigned int ShipsListHandler::getMaxTypeNum(const std::string& name) const
{
    unsigned int index = 0;
    if (name == shiptype::name::DESTROYER)
    {
        index = shiptype::maxnum::arrayindex::DESTROYER;
    } else if (name == shiptype::name::SUBMARINE)
    {
        index = shiptype::maxnum::arrayindex::SUBMARINE;
    } else if (name == shiptype::name::CRUISER)
    {
        index = shiptype::maxnum::arrayindex::CRUISER;
    } else if (name == shiptype::name::BATTLESHIP)
    {
        index = shiptype::maxnum::arrayindex::BATTLESHIP;
    } else if (name == shiptype::name::CARRIER)
    {
        index = shiptype::maxnum::arrayindex::CARRIER;
    } else
    {
        return 0;
    }
    return this->shipTypeMaxNumsArray[index];
}

bool ShipsListHandler::isMaxNumSet(const std::string& name) const
{
    bool result = false;
    if (this->getMaxTypeNum(name) != 0)
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::noneMaxNumSet() const
{
    const bool destroyerMaxNumSet = this->isMaxNumSet(name::DESTROYER);
    const bool submarineMaxNumSet = this->isMaxNumSet(name::SUBMARINE);
    const bool cruiserMaxNumSet = this->isMaxNumSet(name::CRUISER);
    const bool battleshipMaxNumSet = this->isMaxNumSet(name::BATTLESHIP);
    const bool carrierMaxNumSet = this->isMaxNumSet(name::CARRIER);

    bool result = false;

    if (!(destroyerMaxNumSet   &&
         submarineMaxNumSet  &&
         cruiserMaxNumSet    &&
         battleshipMaxNumSet &&
         carrierMaxNumSet))
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::onlyFirstMaxNumSet() const
{
    const bool destroyerMaxNumSet = this->isMaxNumSet(name::DESTROYER);
    const bool submarineMaxNumSet = this->isMaxNumSet(name::SUBMARINE);
    const bool cruiserMaxNumSet = this->isMaxNumSet(name::CRUISER);
    const bool battleshipMaxNumSet = this->isMaxNumSet(name::BATTLESHIP);
    const bool carrierMaxNumSet = this->isMaxNumSet(name::CARRIER);

    bool result = false;

    if (destroyerMaxNumSet   &&
       !(submarineMaxNumSet  &&
         cruiserMaxNumSet    &&
         battleshipMaxNumSet &&
         carrierMaxNumSet))
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::onlyTwoFirstMaxNumSet() const
{
    const bool onlyFirstMaxNumSet = this->onlyFirstMaxNumSet();
    const bool submarineMaxNumSet = this->isMaxNumSet(name::SUBMARINE);
    const bool cruiserMaxNumSet = this->isMaxNumSet(name::CRUISER);
    const bool battleshipMaxNumSet = this->isMaxNumSet(name::BATTLESHIP);
    const bool carrierMaxNumSet = this->isMaxNumSet(name::CARRIER);

    bool result = false;

    if (onlyFirstMaxNumSet   &&
        submarineMaxNumSet   &&
       !(cruiserMaxNumSet    &&
         battleshipMaxNumSet &&
         carrierMaxNumSet))
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::onlyThreeFirstMaxNumSet() const
{
    const bool onlyTwoFirstMaxNumSet = this->onlyTwoFirstMaxNumSet();
    const bool cruiserMaxNumSet = this->isMaxNumSet(name::CRUISER);
    const bool battleshipMaxNumSet = this->isMaxNumSet(name::BATTLESHIP);
    const bool carrierMaxNumSet = this->isMaxNumSet(name::CARRIER);

    bool result = false;

    if (onlyTwoFirstMaxNumSet &&
        cruiserMaxNumSet      &&
       !(battleshipMaxNumSet  &&
         carrierMaxNumSet))
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::onlyFourFirstMaxNumSet() const
{
    const bool onlyThreeFirstMaxNumSet = this->onlyThreeFirstMaxNumSet();
    const bool battleshipMaxNumSet = this->isMaxNumSet(name::BATTLESHIP);
    const bool carrierMaxNumSet = this->isMaxNumSet(name::CARRIER);

    bool result = false;

    if (onlyThreeFirstMaxNumSet &&
        battleshipMaxNumSet     &&
       !(carrierMaxNumSet))
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::allMaxNumSet() const
{
    const bool onlyFourFirstMaxNumSet = this->onlyFourFirstMaxNumSet();
    const bool carrierMaxNumSet = this->isMaxNumSet(name::CARRIER);

    bool result = false;

    if (onlyFourFirstMaxNumSet &&
        carrierMaxNumSet)
    {
        result = true;
    }
    return result;
}

////////////////
// deployment //
////////////////
bool ShipsListHandler::isTypeDeployed(const std::string& typeName) const
{
    unsigned int counter = 0;
    for (const Ship& ship : this->getShipsList())
    {
        if (counter == this->getMaxTypeNum(typeName))
        {
            return true;
        } if (ship.getType().getName() == typeName)
        {
            ++counter;
        }
    }
    return false;
}

bool ShipsListHandler::allShipsDeployed() const
{
    using namespace shiptype::name;
    const bool destroyerDeployed = this->isTypeDeployed(name::DESTROYER);
    const bool submarineDeployed = this->isTypeDeployed(name::SUBMARINE);
    const bool cruiserDeployed = this->isTypeDeployed(name::CRUISER);
    const bool battleshipDeployed = this->isTypeDeployed(name::BATTLESHIP);
    const bool carrierDeployed = this->isTypeDeployed(name::CARRIER);

    bool result = false;
    if (destroyerDeployed  &&
        submarineDeployed  &&
        cruiserDeployed    &&
        battleshipDeployed &&
        carrierDeployed)
    {
        result = true;
    }
    return result;
}

bool ShipsListHandler::areShipsAdjacent(const Ship& ship, const Ship& otherShip) const
{
    for (const Position& pos : ship.getPosList())
    {
        for (const Position& adjacentPos : otherShip.getAdjPosList())
        {
            if (pos == adjacentPos)
            {
                return true;
            }
        }
    }
    return false;
}

bool ShipsListHandler::areShipsColliding(const Ship& ship, const Ship& otherShip) const
{
    for (const Position& pos : ship.getPosList())
    {
        for (const Position& collidingPos : otherShip.getPosList())
        {
            if (pos == collidingPos)
            {
                return true;
            }
        }
    }
    return false;
}

bool ShipsListHandler::isAdjacent(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : this->getShipsList())
    {
        if (this->areShipsAdjacent(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool ShipsListHandler::isColliding(const Ship& ship) const
{
    bool result = false;
    for (const Ship& listShip : this->getShipsList())
    {
        if (this->areShipsColliding(ship, listShip))
        {
            result = true;
        }
    }
    return result;
}

bool ShipsListHandler::isShipVerified(const Ship& ship) const
{
    //@TODO
    return true;
}

/////////////////////////////////
// used after board is resized //
/////////////////////////////////
void ShipsListHandler::rearrangeShipsList()
{
    //@TODO
}

//////////
// battle //
//

bool ShipsListHandler::allShipsSunk() const
{
    for (Ship ship : this->getShipsList())
    {
        if (!ship.isSunk())
        {
            return false;
        }
    }
    return true;
}
