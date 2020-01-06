#include "gamestatecontroller.h"

GameStateController::GameStateController(GameStatePtr gameStatePtr) :
    GameStateHandler(gameStatePtr) {}

void GameStateController::onUpdate(const std::string& input)
{
    //@TODO
}

GameStatePtr GameStateController::getGameStatePtr() const
{
    return GameStateHandler::getGameStatePtr();
}

void GameStateController::setGameStatePtr(const game::state& state)
{
    GameStateHandler::setGameStatePtr(state);
}
