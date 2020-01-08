#include "inputhandler.h"

void InputHandler::getObservers(const Game& game)
{
    Subject::addObserver(game.getGameStateHandlerPtr());
    Subject::addObserver(game.getBoardHandlerPtr());
    Subject::addObserver(game.getConfigsListHandlerPtr());
    Subject::addObserver(game.getShipsListHandlerPtr());
    Subject::addObserver(game.getShotsListHandlerPtr());
    Subject::addObserver(game.getMsgHandlerPtr());
}

void InputHandler::readInput()
{
    std::getline(std::cin, this->input);
}

void InputHandler::parseInput()
{
    //@TODO
}

void InputHandler::updateGame()
{
    Subject::update(this->input);
}
