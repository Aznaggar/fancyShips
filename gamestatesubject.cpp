#include "gamestatesubject.h"

void GameStateSubject::addGameStateObserver(GameStateObserverPtr gameStateObserverPtr)
{
    this->gameStateObserverPtrsList.push_back(gameStateObserverPtr);
}

void GameStateSubject::removeGameStateObserver(GameStateObserverPtr gameStateObserverPtr)
{
    this->gameStateObserverPtrsList.remove(gameStateObserverPtr);
}

void GameStateSubject::updateGameState(const game::state& state)
{
    for (GameStateObserverPtr& gameStateObserverPtr: this->gameStateObserverPtrsList)
    {
        gameStateObserverPtr->onGameStateUpdate(state);
    }
}
