#include "game.h"

Game::Game() :
    gameStatePtr(std::make_shared<game::state>(game::state::ENTRY)),
    boardPtr(std::make_shared<Board>()),
    configsListPtr(std::make_shared<std::list<Config>>()),
    shipsListPtr(std::make_shared<std::list<Ship>>()),
    shotsListPtr(std::make_shared<std::list<battle::shot>>()) {}

void Game::run()
{
    this->gameStateHandlerPtr = std::make_shared<GameStateHandler>(this->gameStatePtr);
    this->boardHandlerPtr = std::make_shared<BoardHandler>(this->boardPtr,
                                                           this->shipsListPtr,
                                                           this->gameStatePtr);
    this->configsListHandlerPtr = std::make_shared<ConfigsListHandler>(this->configsListPtr,
                                                                       this->gameStatePtr);
    this->shipsListHandlerPtr = std::make_shared<ShipsListHandler>(this->shipsListPtr,
                                                                   this->configsListPtr,
                                                                   this->gameStatePtr,
                                                                    this->boardPtr);
    this->shotsListHandlerPtr = std::make_shared<ShotsListHandler>(this->shotsListPtr,
                                                                   this->shipsListPtr,
                                                                   this->gameStatePtr);
    this->msgHandlerPtr = std::make_shared<MsgHandler>(this->msg,
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

ShipsListHandlerPtr Game::getShipsListHandlerPtr() const
{
    return this->shipsListHandlerPtr;
}
ShotsListHandlerPtr Game::getShotsListHandlerPtr() const
{
    return this->shotsListHandlerPtr;
}

MsgHandlerPtr Game::getMsgHandlerPtr() const
{
    return this->msgHandlerPtr;
}
