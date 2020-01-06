#pragma once
#include <string>

#include "gameconstants.h"

class Observer
{
public:
    virtual ~Observer() {}
    virtual void onUpdate(const std::string&) = 0;
};
