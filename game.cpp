#include "game.h"

Game::Game() :
    gameState(game::state::CONFIG),
    boardPtr(std::make_shared<Board>()),
    shipsListPtr(std::make_shared<std::list<Ship>>()),
    shotsListPtr(std::make_shared<std::list<battle::shot>>()) {}

void Game::run(InputHandlerPtr inputHandlerPtr)
{
    this->initHandlers();
    this->provideObservers(inputHandlerPtr);
}

void Game::initHandlers()
{
    this->shipsListHandlerPtr = std::make_shared<ShipsListHandler>(this->shipsListPtr,
                                                                   this->boardPtr);
    this->gameStateProviderPtr = std::make_shared<GameStateProvider>(this->gameState,
                                                                     this->shipsListHandlerPtr);
    this->boardHandlerPtr = std::make_shared<BoardHandler>(this->boardPtr,
                                                           this->shipsListPtr);
    this->shotsListHandlerPtr = std::make_shared<ShotsListHandler>(this->shotsListPtr,
                                                                   this->shipsListPtr);
    this->msgHandlerPtr = std::make_shared<MsgHandler>(this->msg,
                                                       this->shipsListHandlerPtr);
}

void Game::provideObservers(InputHandlerPtr inputHandlerPtr)
{
    inputHandlerPtr->getObservers(this->gameStateProviderPtr,
                                  this->boardHandlerPtr,
                                  this->shipsListHandlerPtr,
                                  this->shotsListHandlerPtr);
    this->gameStateProviderPtr->getObservers(this->boardHandlerPtr,
                                             this->shotsListHandlerPtr,
                                             this->msgHandlerPtr);
}

bool Game::isRunning() const
{
    return this->gameState != game::state::END;
}

void Game::print() const
{
    this->clearScreen();
    this->boardHandlerPtr->print();
    this->shotsListHandlerPtr->print();
    this->msgHandlerPtr->print();
}

void Game::clearScreen() const
{
    std::cout << game::screen::CLEAR_CMD;
}

void Game::updateGame()
{
    this->gameStateProviderPtr->updateGameState();
}
