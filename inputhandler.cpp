#include "inputhandler.h"

void InputHandler::getObservers(const Game& game)
{
    Subject::addObserver(game.getBoardControllerPtr());
    Subject::addObserver(game.getConfigControllerPtr());
    Subject::addObserver(game.getDeploymentControllerPtr());
    Subject::addObserver(game.getBattleControllerPtr());
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
