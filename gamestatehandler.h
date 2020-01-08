#pragma once
#include <memory>

#include "observer.h"

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

class GameStateHandler : public Observer
{
private:
    GameStatePtr gameStatePtr;

    const game::state& getGameState() const;
    void setGameStatePtr(const game::state&);
public:
    GameStateHandler(GameStatePtr);
    ~GameStateHandler();

    void onUpdate(const std::string&) override;

};

using GameStateHandlerPtr = std::shared_ptr<GameStateHandler>;
