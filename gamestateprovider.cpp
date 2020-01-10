#include "gamestateprovider.h"

GameStateProvider::GameStateProvider(const game::state& gameState,
                                     ShipsListHandlerPtr shipsListHandlerPtr) :
    gameState(gameState),
    shipsListHandlerPtr(shipsListHandlerPtr) {}

GameStateProvider::~GameStateProvider()
{
    this->shipsListHandlerPtr.reset();
}

void GameStateProvider::getObservers(BoardHandlerPtr boardHandlerPtr,
                                     ShotsListHandlerPtr shotsListHandlerPtr,
                                     MsgHandlerPtr msgHandlerPtr)
{
    GameStateSubject::addGameStateObserver(this->shipsListHandlerPtr);
    GameStateSubject::addGameStateObserver(boardHandlerPtr);
    GameStateSubject::addGameStateObserver(shotsListHandlerPtr);
    GameStateSubject::addGameStateObserver(msgHandlerPtr);
}

void GameStateProvider::setGameState()
{
    const bool allMaxNumSet = this->shipsListHandlerPtr->allMaxNumSet();
    const bool allShipsDeployed = this->shipsListHandlerPtr->allShipsDeployed();
    const bool allShipsSunk = this->shipsListHandlerPtr->allShipsSunk();

    switch (this->gameState)
    {
    case game::state::CONFIG:
        if (allMaxNumSet)
        {
            this->gameState = game::state::DEPLOYMENT;
        }
        else if (this->inputEquals(commands::END_GAME))
        {
            this->gameState = game::state::END;
        }
        break;
    case game::state::DEPLOYMENT:
        if (allShipsDeployed || this->inputEquals(commands::FINISH_DEVELOPMENT))
        {
            this->gameState = game::state::DEPLOYMENT;
        }
        else if (this->inputEquals(commands::END_GAME))
        {
            this->gameState = game::state::END;
        }
        break;
    case state::BATTLE:
        if (allShipsSunk || this->inputEquals(commands::END_GAME))
        {
            this->gameState = state::END;
        }
        break;
    case game::state::END:
        break;
    default:
        break;
    }
}

bool GameStateProvider::inputEquals(const std::string& command) const
{
    bool result = false;

    if (this->input == command)
    {
        result = true;
    }
    return result;
}

void GameStateProvider::updateGameState()
{
    this->setGameState();
    GameStateSubject::updateGameState(this->gameState);
}

void GameStateProvider::onInputUpdate(const std::string& input)
{
    this->input = input;
}
