#pragma once
#include <list>
#include <memory>

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

class ShotsListHandler
{
private:
    ShotsListPtr shotsListPtr;
protected:
    void setShotsListPtr(ShotsListPtr);
    void addShot(const battle::shot&);
public:
    ShotsListHandler(ShotsListPtr);
    virtual ~ShotsListHandler();
    ShotsListPtr getShotsListPtr() const;
};
