#pragma once
#include <list>
#include <memory>

#include "shipslisthandler.h"
#include "configslisthandler.h"
#include "boardhandler.h"
#include "gamestatehandler.h"
#include "observer.h"


class ShipsListController :
     protected ShipsListHandler,
     private ConfigsListHandler,
     private GameStateHandler,
     private BoardHandler,
     public Observer
{
private:
    bool areShipsAdjacent(const Ship&, const Ship&) const;
    bool areShipsColliding(const Ship&, const Ship&) const;

    bool isAdjacent(const Ship&) const;
    bool isColliding(const Ship&) const;

    ShipsListPtr getShipsListPtr() const;
    void addShip(const Ship&);
    void setShipList(ShipsListPtr);

    ConfigsListPtr getConfigsListPtr() const;
    GameStatePtr getGameStatePtr() const;
    BoardPtr getBoardPtr() const;
public:
    ShipsListController(ShipsListPtr,
                        ConfigsListPtr,
                        GameStatePtr,
                        BoardPtr);


    bool isShipVerified(const Ship& ship) const;
    void rearrangeShipsList();

    void onUpdate(const std::string&) override;
};

using ShipsListControllerPtr = std::shared_ptr<ShipsListController>;
