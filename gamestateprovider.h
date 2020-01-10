#pragma once

#include "gamestatesubject.h"
#include "inputobserver.h"
#include "boardhandler.h"
#include "shipslisthandler.h"
#include "shotslisthandler.h"
#include "msghandler.h"

using namespace game::commands;

class GameStateProvider :
        public GameStateSubject,
        public InputObserver
{
private:
    std::string input;
    game::state gameState;
    ShipsListHandlerPtr shipsListHandlerPtr;

    void setGameState();
    bool inputEquals(const std::string&) const;
public:
    GameStateProvider(const game::state&,
                      ShipsListHandlerPtr);
    ~GameStateProvider();
    void getObservers(BoardHandlerPtr,
                      ShotsListHandlerPtr,
                      MsgHandlerPtr);
    void updateGameState();
    void onInputUpdate(const std::string&) override;
};

using GameStateProviderPtr = std::shared_ptr<GameStateProvider>;
