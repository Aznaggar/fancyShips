#pragma once
#include <list>
#include <memory>

#include "observer.h"

using ObserverPtr = std::shared_ptr<Observer>;

class Subject
{
private:
    std::list<ObserverPtr> observersList;
protected:
    void update(const std::string&);
public:
    void addObserver(ObserverPtr);
    void removeObserver(ObserverPtr);
};
