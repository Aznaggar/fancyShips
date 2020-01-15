#pragma once
#include <iostream>
#include "gamestateobserver.h"

class IPrintable
{
public:
    virtual ~IPrintable() {}
    virtual void print(const game::state&) const = 0;
};
