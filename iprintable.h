#pragma once
#include <iostream>

class IPrintable
{
public:
    virtual ~IPrintable() {}
    virtual void print() const = 0;
};
