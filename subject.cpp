#include "subject.h"

void Subject::addObserver(ObserverPtr observer)
{
    this->observersList.push_back(observer);
}

void Subject::removeObserver(ObserverPtr observer)
{
    this->observersList.remove(observer);
}

void Subject::update(const std::string& input)
{
    for (ObserverPtr& observer : this->observersList)
    {
        observer->onUpdate(input);
    }
}
