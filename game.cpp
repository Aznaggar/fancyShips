#include "game.h"

Game::Game() {}

void Game::run()
{
    this->state = game::state::ENTRY;
    this->boardPtr = std::make_shared<Board>();
    this->shipsListPtr = std::make_shared<std::list<Ship>>();
    this->configsListPtr = std::make_shared<std::list<Config>>();
    this->boardControllerPtr = std::make_shared<BoardController>(this->boardPtr,
                                                                 this->shipsListPtr);
    this->configControllerPtr = std::make_shared<ConfigController>(this->configsListPtr);
    this->deploymentControllerPtr = std::make_shared<DeploymentController>(this->shipsListPtr,
                                                                           this->configsListPtr,
                                                                           this->boardPtr);
    this->battleControllerPtr = std::make_shared<BattleController>(this->shipsListPtr);
}

bool Game::isRunning() const
{
    //@TODO
    return true;
}

BoardControllerPtr Game::getBoardControllerPtr() const
{
    return this->boardControllerPtr;
}

ConfigControllerPtr Game::getConfigControllerPtr() const
{
    return this->configControllerPtr;
}

DeploymentControllerPtr Game::getDeploymentControllerPtr() const
{
    return this->deploymentControllerPtr;
}

BattleControllerPtr Game::getBattleControllerPtr() const
{
    return this->battleControllerPtr;
}
