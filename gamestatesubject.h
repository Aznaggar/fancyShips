#pragma once
#include <list>
#include <memory>

#include "gamestateobserver.h"

using GameStateObserverPtr = std::shared_ptr<GameStateObserver>;

class GameStateSubject
{
private:
    std::list<GameStateObserverPtr> gameStateObserverPtrsList;
protected:
    void updateGameState(const game::state&);
public:
    void addGameStateObserver(GameStateObserverPtr);
    void removeGameStateObserver(GameStateObserverPtr);
};
