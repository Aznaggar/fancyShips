#pragma once

namespace game
{
  enum class state
  {
    CONFIG,
    DEPLOYMENT,
    BATTLE,
    END
  };
}

class GameStateObserver
{
public:
    virtual ~GameStateObserver() {}
    virtual void onGameStateUpdate(const game::state&) = 0;
};
