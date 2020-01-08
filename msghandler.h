#pragma once

#include "gamestatehandler.h"
#include "observer.h"
#include "iprintable.h"

namespace game
{
  namespace message
  {
    const std::string INVALID_OPTION = "Invalid option chosen. ";
    const std::string INVALID_INPUT = "Invalid input given. ";

    const std::string DEPLOYMENT_CHOICE = "Manual / automatic deployment?(m/a): ";
    const std::string SHIPS_LIST_TYPE_ADDITION = "Max number of ";
  }
}

using namespace game;

class MsgHandler :
        public Observer,
        public IPrintable
{
private:
    std::string msg;
    GameStatePtr gameStatePtr;

    const std::string& getMsg() const;
    const game::state& getGameState() const;

    void setMsg(const std::string&);
public:
    MsgHandler(const std::string&, GameStatePtr);
    ~MsgHandler();

    void print() const override;
    void onUpdate(const std::string&) override;
};

using MsgHandlerPtr = std::shared_ptr<MsgHandler>;
