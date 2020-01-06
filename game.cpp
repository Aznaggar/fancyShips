#include "game.h"

Game::Game() :
    gameStatePtr(std::make_shared<game::state>(game::state::ENTRY)),
    boardPtr(std::make_shared<Board>()),
    configsListPtr(std::make_shared<std::list<Config>>()),
    shipsListPtr(std::make_shared<std::list<Ship>>()),
    shotsListPtr(std::make_shared<ShotsList>()),
    msgPtr(std::make_shared<std::string>()) {}

void Game::run()
{
    this->gameStateControllerPtr = std::make_shared<GameStateController>(this->gameStatePtr);
    this->boardControllerPtr = std::make_shared<BoardController>(this->boardPtr,
                                                                 this->shipsListPtr,
                                                                 this->gameStatePtr);
    this->configControllerPtr = std::make_shared<ConfigController>(this->configsListPtr,
                                                                   this->gameStatePtr);
    this->shipsListControllerPtr = std::make_shared<ShipsListController>(this->shipsListPtr,
                                                                         this->configsListPtr,
                                                                         this->gameStatePtr,
                                                                         this->boardPtr);
    this->shotsListControllerPtr = std::make_shared<ShotsListController>(this->shotsListPtr,
                                                                         this->shipsListPtr,
                                                                         this->gameStatePtr);
    this->msgControllerPtr = std::make_shared<MsgController>(this->msgPtr,
                                                             this->gameStatePtr);
}

bool Game::isRunning() const
{
    return *this->gameStatePtr != game::state::END;
}

GameStateControllerPtr Game::getGameStateControllerPtr() const
{
    return this->gameStateControllerPtr;
}

BoardControllerPtr Game::getBoardControllerPtr() const
{
    return this->boardControllerPtr;
}

ConfigControllerPtr Game::getConfigControllerPtr() const
{
    return this->configControllerPtr;
}

ShipsListControllerPtr Game::getShipsListControllerPtr() const
{
    return this->shipsListControllerPtr;
}
ShotsListControllerPtr Game::getShotsListControllerPtr() const
{
    return this->shotsListControllerPtr;
}

MsgControllerPtr Game::getMsgControllerPtr() const
{
    return this->msgControllerPtr;
}
