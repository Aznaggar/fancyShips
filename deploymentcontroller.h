#pragma once
#include <list>
#include <memory>

#include "configslisthandler.h"
#include "shipslisthandler.h"
#include "board.h"
#include "observer.h"


class DeploymentController :
     public ShipsListHandler,
     private ConfigsListHandler,
     public Observer
{
private:
    BoardPtr boardPtr;

    bool areShipsAdjacent(const Ship&, const Ship&) const;
    bool areShipsColliding(const Ship&, const Ship&) const;

    bool isAdjacent(const Ship&) const;
    bool isColliding(const Ship&) const;

public:
    DeploymentController(ShipsListPtr,
                         ConfigsListPtr,
                         BoardPtr);


    bool isShipVerified(const Ship& ship) const;
    void rearrangeShipsList();
};

using DeploymentControllerPtr = std::shared_ptr<DeploymentController>;
