#pragma once

#include "observer.h"
#include "gamestatehandler.h"

class GameStateController :
        public GameStateHandler,
        public Observer
{
private:
    GameStatePtr getGameStatePtr() const;
    void setGameStatePtr(const game::state&);
public:
    GameStateController(GameStatePtr);

    void onUpdate(const std::string&) override;
};

using GameStateControllerPtr = std::shared_ptr<GameStateController>;
