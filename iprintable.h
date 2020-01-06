#pragma once
#include <iostream>

#include "gamestatehandler.h"

class IPrintable
{
public:
    virtual ~IPrintable() {}
    virtual void print() const = 0;
};
