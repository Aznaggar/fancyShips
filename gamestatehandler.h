#pragma once
#include <memory>

namespace game
{
  enum class state
  {
    ENTRY,
    SHIPS_LIST_CONFIG,
    DEPLOYMENT,
    WAITING_FOR_BATTLE,
    IDLE,
    BATTLE,
    END
  };
}

using GameStatePtr = std::shared_ptr<game::state>;

class GameStateHandler
{
private:
    GameStatePtr gameStatePtr;
protected:
    void setGameStatePtr(GameStatePtr);
    void setGameStatePtr(const game::state&);
public:
    GameStateHandler(GameStatePtr);
    virtual ~GameStateHandler();

    GameStatePtr getGameStatePtr() const;
};
