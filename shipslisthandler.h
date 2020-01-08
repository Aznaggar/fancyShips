#pragma once

#include "ship.h"
#include "shiptypeconfig.h"
#include "gamestatehandler.h"
#include "board.h"
#include "observer.h"

class ShipsListHandler : public Observer
{
private:
    ShipsListPtr shipsListPtr;
    ConfigsListPtr configsListPtr;
    GameStatePtr gameStatePtr;
    BoardPtr boardPtr;

    const std::list<Ship>& getShipsList() const;
    const std::list<Config>& getConfigsList() const;
    const game::state& getGameState() const;
    const Board& getBoard() const;

    void setShipListPtr(const std::list<Ship>&);
    void addShip(const Ship&);

    bool areShipsAdjacent(const Ship&, const Ship&) const;
    bool areShipsColliding(const Ship&, const Ship&) const;

    bool isAdjacent(const Ship&) const;
    bool isColliding(const Ship&) const;

    bool isShipVerified(const Ship& ship) const;
    void rearrangeShipsList();
public:
    ShipsListHandler(ShipsListPtr,
                     ConfigsListPtr,
                     GameStatePtr,
                     BoardPtr);
    ~ShipsListHandler();

    void onUpdate(const std::string&) override;
};

using ShipsListHandlerPtr = std::shared_ptr<ShipsListHandler>;
