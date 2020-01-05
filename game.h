#pragma once

#include "boardcontroller.h"
#include "configcontroller.h"
#include "deploymentcontroller.h"
#include "battlecontroller.h"
#include "gameconstants.h"

class Game
{
private:
    game::state state;
    BoardPtr boardPtr;
    ShipsListPtr shipsListPtr;
    ConfigsListPtr configsListPtr;

    BoardControllerPtr boardControllerPtr;
    ConfigControllerPtr configControllerPtr;
    DeploymentControllerPtr deploymentControllerPtr;
    BattleControllerPtr battleControllerPtr;

public:
    Game();
    void run();
    bool isRunning() const;

    BoardControllerPtr getBoardControllerPtr() const;
    ConfigControllerPtr getConfigControllerPtr() const;
    DeploymentControllerPtr getDeploymentControllerPtr() const;
    BattleControllerPtr getBattleControllerPtr() const;
};

// std::make_tuple(1, 2, ship::dir::HOR, 3),
// std::make_tuple(2, 4, ship::dir::HOR, 3),
// std::make_tuple(0, 0, ship::dir::HOR, 3),
// std::make_tuple(8, 9, ship::dir::HOR, 3),
// std::make_tuple(0, 2, ship::dir::VERT, 5),
// std::make_tuple(9, 5, ship::dir::HOR, 4)
