#include "boardhandler.h"

BoardHandler::BoardHandler(BoardPtr boardPtr,
                           ShipsListPtr shipsListPtr) :
    boardPtr(boardPtr),
    shipsListPtr(shipsListPtr) {}

BoardHandler::~BoardHandler()
{
    this->boardPtr.reset();
    this->shipsListPtr.reset();
}

void BoardHandler::print(const state& gameState) const
{
    switch (gameState)
    {
    case state::CONFIG:
        this->printEmpty();
        break;
    case state::DEPLOYMENT:
        if (this->getShipsList().empty())
        {
            this->printEmpty();
        }
        else
        {
            this->printNonEmpty();
        }
        break;
    case state::BATTLE:
        this->printBattle();
        break;
    case state::END:
        break;
    default:
        break;
    }
}

void BoardHandler::onInputUpdate(const std::string& input)
{
    this->input = input;
}

void BoardHandler::onGameStateUpdate(const state& gameState)
{
    switch (gameState)
    {
    case state::CONFIG:
        break;
    case state::DEPLOYMENT:
        if (resizeChosen)
        {
            if (input::functions::INPUT_MATCHES_PATTERN(patterns::BOARD_RESIZE_GENERAL,
                                                        this->input))
            {
                const CoordsPair coordsPair = input::functions::PARSE_COORDS_INPUT(this->input);

                this->boardPtr->resize(coordsPair.first,
                                       coordsPair.second);
                resizeChosen = false;

            }
        }
        if (this->input == commands::BOARD_RESIZE)
        {
            resizeChosen = true;
        }
        break;
    case state::BATTLE:
        break;
    case state::END:
        break;
    default:
        break;
    }
}

const Board& BoardHandler::getBoard() const
{
    return *this->boardPtr;
}

const std::list<Ship>& BoardHandler::getShipsList() const
{
    return *this->shipsListPtr;
}


void BoardHandler::printEmpty() const
{
    //@TODO
}

void BoardHandler::printNonEmpty() const
{
    //@TODO
}

void BoardHandler::printBattle() const
{
    //@TODO
}

