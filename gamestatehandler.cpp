#include "gamestatehandler.h"

GameStateHandler::GameStateHandler(GameStatePtr gameStatePtr) :
    gameStatePtr(gameStatePtr) {}

GameStateHandler::~GameStateHandler()
{
    this->gameStatePtr.reset();
}

GameStatePtr GameStateHandler::getGameStatePtr() const
{
    return this->gameStatePtr;
}

void GameStateHandler::setGameStatePtr(const game::state& state)
{
    this->gameStatePtr = std::make_shared<game::state>(state);
}

void GameStateHandler::setGameStatePtr(GameStatePtr gameStatePtr)
{
    this->gameStatePtr = gameStatePtr;
}
