#pragma once

#include "shipslisthandler.h"
#include "observer.h"


class BattleController :
        private ShipsListHandler,
        public Observer
{
//std::list<Shot> shotsList;

public:
    BattleController(ShipsListPtr);
};

using BattleControllerPtr = std::shared_ptr<BattleController>;
