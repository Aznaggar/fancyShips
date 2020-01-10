#pragma once

#include "ship.h"
#include "gamestateobserver.h"
#include "inputobserver.h"
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
        public InputObserver,
        public GameStateObserver,
        public IPrintable
{
private:
    ShotsListPtr shotsListPtr;
    ShipsListPtr shipsListPtr;

    std::string input;

    const std::list<battle::shot>& getShotsList() const;
    const std::list<Ship>& getShipsList() const;

    void addShot(const battle::shot&);
public:
    ShotsListHandler(ShotsListPtr,
                     ShipsListPtr);
    ~ShotsListHandler();

    void onInputUpdate(const std::string&) override;
    void onGameStateUpdate(const game::state&) override;
    void print() const override;
};

using ShotsListPtr = std::shared_ptr<std::list<battle::shot>>;
using ShotsListHandlerPtr = std::shared_ptr<ShotsListHandler>;
