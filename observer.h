#pragma once

#include <string>

class Observer
{
public:
    virtual ~Observer() {}
    virtual void onUpdate(const std::string& input) = 0;
};
