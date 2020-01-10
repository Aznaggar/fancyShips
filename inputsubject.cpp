#include "inputsubject.h"

void InputSubject::addInputObserver(InputObserverPtr inputObserverPtr)
{
    this->inputObserverPtrsList.push_back(inputObserverPtr);
}

void InputSubject::removeInputObserver(InputObserverPtr inputObserverPtr)
{
    this->inputObserverPtrsList.remove(inputObserverPtr);
}

void InputSubject::updateInput(const std::string& input)
{
    for (InputObserverPtr& inputObserverPtr : this->inputObserverPtrsList)
    {
        inputObserverPtr->onInputUpdate(input);
    }
}
