#pragma once

#include "gamestatecontroller.h"
#include "boardcontroller.h"
#include "configcontroller.h"
#include "shipslistcontroller.h"
#include "shotslistcontroller.h"
#include "msgcontroller.h"

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
    MsgPtr msgPtr;

    GameStateControllerPtr gameStateControllerPtr;
    BoardControllerPtr boardControllerPtr;
    ConfigControllerPtr configControllerPtr;
    ShipsListControllerPtr shipsListControllerPtr;
    ShotsListControllerPtr shotsListControllerPtr;
    MsgControllerPtr msgControllerPtr;

public:
    Game();
    void run();
    bool isRunning() const;

    GameStateControllerPtr getGameStateControllerPtr() const;
    BoardControllerPtr getBoardControllerPtr() const;
    ConfigControllerPtr getConfigControllerPtr() const;
    ShipsListControllerPtr getShipsListControllerPtr() const;
    ShotsListControllerPtr getShotsListControllerPtr() const;
    MsgControllerPtr getMsgControllerPtr() const;

};

// std::make_tuple(1, 2, ship::dir::HOR, 3),
// std::make_tuple(2, 4, ship::dir::HOR, 3),
// std::make_tuple(0, 0, ship::dir::HOR, 3),
// std::make_tuple(8, 9, ship::dir::HOR, 3),
// std::make_tuple(0, 2, ship::dir::VERT, 5),
// std::make_tuple(9, 5, ship::dir::HOR, 4)
