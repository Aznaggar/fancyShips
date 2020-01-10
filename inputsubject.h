#pragma once
#include <list>
#include <memory>

#include "inputobserver.h"

using InputObserverPtr = std::shared_ptr<InputObserver>;

class InputSubject
{
private:
    std::list<InputObserverPtr> inputObserverPtrsList;
protected:
    void updateInput(const std::string&);
public:
    void addInputObserver(InputObserverPtr);
    void removeInputObserver(InputObserverPtr);
};
