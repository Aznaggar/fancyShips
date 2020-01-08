#include "gamestatehandler.h"

GameStateHandler::GameStateHandler(GameStatePtr gameStatePtr) :
    gameStatePtr(gameStatePtr) {}

GameStateHandler::~GameStateHandler()
{
    this->gameStatePtr.reset();
}

void GameStateHandler::onUpdate(const std::string& input)
{
    //@TODO
}

const game::state& GameStateHandler::getGameState() const
{
    return *this->gameStatePtr;
}

void GameStateHandler::setGameStatePtr(const game::state& state)
{
    this->gameStatePtr = std::make_shared<game::state>(state);
}
