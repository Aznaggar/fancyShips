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
    this->gameStateHandlerPtr = std::make_shared<GameStateHandler>(this->gameStatePtr);
    this->boardHandlerPtr = std::make_shared<BoardHandler>(this->boardPtr,
                                                           this->shipsListPtr,
                                                           this->gameStatePtr);
    this->configsListHandlerPtr = std::make_shared<ConfigsListHandler>(this->configsListPtr,
                                                                       this->gameStatePtr);
    this->shipsListControllerPtr = std::make_shared<ShipsListController>(this->shipsListPtr,
                                                                         this->configsListPtr,
                                                                         this->gameStatePtr,
                                                                         this->boardPtr);
    this->shotsListControllerPtr = std::make_shared<ShotsListController>(this->shotsListPtr,
                                                                         this->shipsListPtr,
                                                                         this->gameStatePtr);
    this->msgHandlerPtr = std::make_shared<MsgHandler>(this->msgPtr,
                                                       this->gameStatePtr);
}

bool Game::isRunning() const
{
    return *this->gameStatePtr != game::state::END;
}

GameStateHandlerPtr Game::getGameStateHandlerPtr() const
{
    return this->gameStateHandlerPtr;
}

BoardHandlerPtr Game::getBoardHandlerPtr() const
{
    return this->boardHandlerPtr;
}

ConfigsListHandlerPtr Game::getConfigsListHandlerPtr() const
{
    return this->configsListHandlerPtr;
}

ShipsListControllerPtr Game::getShipsListControllerPtr() const
{
    return this->shipsListControllerPtr;
}
ShotsListControllerPtr Game::getShotsListControllerPtr() const
{
    return this->shotsListControllerPtr;
}

MsgHandlerPtr Game::getMsgHandlerPtr() const
{
    return this->msgHandlerPtr;
}
