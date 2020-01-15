#pragma once

#include "inputhandler.h"
#include "gamestateprovider.h"

class Game
{
private:
    game::state gameState;
    BoardPtr boardPtr;
    ShipsListPtr shipsListPtr;
    ShotsListPtr shotsListPtr;
    std::string msg;

    GameStateProviderPtr gameStateProviderPtr;
    BoardHandlerPtr boardHandlerPtr;
    ShipsListHandlerPtr shipsListHandlerPtr;
    ShotsListHandlerPtr shotsListHandlerPtr;
    MsgHandlerPtr msgHandlerPtr;

    void initHandlers();
    void provideObservers(InputHandlerPtr);
public:

    Game();
    ~Game();
    void run(InputHandlerPtr);
    bool isRunning() const;
    void printGame() const;
    void updateGame(InputHandlerPtr);
};
