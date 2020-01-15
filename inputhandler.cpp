#include "inputhandler.h"

void InputHandler::getObservers(GameStateProviderPtr gameStateProviderPtr,
                                BoardHandlerPtr boardHandlerPtr,
                                ShipsListHandlerPtr shipsListHandlerPtr,
                                ShotsListHandlerPtr shotsListHandlerPtr)
{
    InputSubject::addInputObserver(gameStateProviderPtr);
    InputSubject::addInputObserver(boardHandlerPtr);
    InputSubject::addInputObserver(shipsListHandlerPtr);
    InputSubject::addInputObserver(shotsListHandlerPtr);
}

void InputHandler::readInput()
{
    std::getline(std::cin, this->input);
}

void InputHandler::updateInput()
{
    InputSubject::updateInput(this->input);
}
