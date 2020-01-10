#pragma once

#include "inputhandler.h"
#include "gamestateprovider.h"

namespace game
{
    namespace screen
    {
        const std::string CLEAR_CMD = "\033[2J\033[0;0H";
    }
}

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
    void clearScreen() const;
public:

    Game();
    void run(InputHandlerPtr);
    bool isRunning() const;
    void print() const;
    void updateGame();
};

// std::make_tuple(1, 2, ship::dir::HOR, 3),
// std::make_tuple(2, 4, ship::dir::HOR, 3),
// std::make_tuple(0, 0, ship::dir::HOR, 3),
// std::make_tuple(8, 9, ship::dir::HOR, 3),
// std::make_tuple(0, 2, ship::dir::VERT, 5),
// std::make_tuple(9, 5, ship::dir::HOR, 4)
