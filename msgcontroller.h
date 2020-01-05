#pragma once

#include "observer.h"
#include "iprintable.h"


class MsgController :
        public IPrintable,
        public Observer
{
public:
    void print(const game::state&) const;
};
