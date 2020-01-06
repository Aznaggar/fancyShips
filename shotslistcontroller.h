#pragma once

#include "shotslisthandler.h"
#include "shipslisthandler.h"
#include "gamestatehandler.h"
#include "iprintable.h"
#include "observer.h"

class ShotsListController :
        protected ShotsListHandler,
        private ShipsListHandler,
        private GameStateHandler,
        public IPrintable,
        public Observer
{
private:
    ShotsListPtr getShotsListPtr() const;
    void addShot(const battle::shot&);

    ShipsListPtr getShipsListPtr() const;
    GameStatePtr getGameStatePtr() const;

public:
    ShotsListController(ShotsListPtr, ShipsListPtr, GameStatePtr);

    void print() const override;
    void onUpdate(const std::string&) override;
};

using ShotsListControllerPtr = std::shared_ptr<ShotsListController>;
