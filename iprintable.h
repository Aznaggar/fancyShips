#pragma once
#include <iostream>

#include "gameconstants.h"

class IPrintable
{
public:
    virtual ~IPrintable() {}
    virtual void print(const game::state&) = 0;
};
