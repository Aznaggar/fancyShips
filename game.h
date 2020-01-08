#pragma once

#include "boardhandler.h"
#include "configslisthandler.h"
#include "shipslisthandler.h"
#include "shotslisthandler.h"
#include "msghandler.h"

namespace game
{
    namespace screen
    {
      namespace clear
      {
        const std::string COMMAND = "\033[2J\033[0;0H";
        const bool ENABLED = true;
        const bool DISABLED = false;
      }
    }
}

class Game
{
private:
    GameStatePtr gameStatePtr;
    BoardPtr boardPtr;
    ConfigsListPtr configsListPtr;
    ShipsListPtr shipsListPtr;
    ShotsListPtr shotsListPtr;
    std::string msg;

    GameStateHandlerPtr gameStateHandlerPtr;
    BoardHandlerPtr boardHandlerPtr;
    ConfigsListHandlerPtr configsListHandlerPtr;
    ShipsListHandlerPtr shipsListHandlerPtr;
    ShotsListHandlerPtr shotsListHandlerPtr;
    MsgHandlerPtr msgHandlerPtr;

public:
    Game();
    void run();
    bool isRunning() const;

    GameStateHandlerPtr getGameStateHandlerPtr() const;
    BoardHandlerPtr getBoardHandlerPtr() const;
    ConfigsListHandlerPtr getConfigsListHandlerPtr() const;
    ShipsListHandlerPtr getShipsListHandlerPtr() const;
    ShotsListHandlerPtr getShotsListHandlerPtr() const;
    MsgHandlerPtr getMsgHandlerPtr() const;

};

// std::make_tuple(1, 2, ship::dir::HOR, 3),
// std::make_tuple(2, 4, ship::dir::HOR, 3),
// std::make_tuple(0, 0, ship::dir::HOR, 3),
// std::make_tuple(8, 9, ship::dir::HOR, 3),
// std::make_tuple(0, 2, ship::dir::VERT, 5),
// std::make_tuple(9, 5, ship::dir::HOR, 4)
