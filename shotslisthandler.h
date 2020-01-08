#pragma once

#include "ship.h"
#include "gamestatehandler.h"
#include "observer.h"
#include "iprintable.h"

namespace game
{
    namespace battle
    {
        enum class shot
        {
            HIT,
            MISS,
            SUNK
        };
    }
}

using namespace game;
using ShotsList = std::list<battle::shot>;
using ShotsListPtr = std::shared_ptr<ShotsList>;

class ShotsListHandler :
        public Observer,
        public IPrintable
{
private:
    ShotsListPtr shotsListPtr;
    ShipsListPtr shipsListPtr;
    GameStatePtr gameStatePtr;

    const std::list<battle::shot>& getShotsList() const;
    const std::list<Ship>& getShipsList() const;
    const game::state& getGameState() const;

    void addShot(const battle::shot&);
public:
    ShotsListHandler(ShotsListPtr,
                     ShipsListPtr,
                     GameStatePtr);
    ~ShotsListHandler();

    void onUpdate(const std::string&) override;
    void print() const override;

};

using ShotsListPtr = std::shared_ptr<std::list<battle::shot>>;
using ShotsListHandlerPtr = std::shared_ptr<ShotsListHandler>;
