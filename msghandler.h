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

//using game;

using MsgPtr = std::shared_ptr<std::string>;

class MsgHandler :
        private GameStateHandler,
        public Observer,
        public IPrintable
{
private:
    MsgPtr msgPtr;
    GameStatePtr gameStatePtr;

public:
    MsgHandler(MsgPtr, GameStatePtr);
    ~MsgHandler();

    void print() const override;
    void onUpdate(const std::string&) override;

    MsgPtr getMsgPtr() const;
    const std::string& getMsg() const;
    const game::state& getGameState() const;

    void setMsgPtr(const std::string&);
    void setMsgPtr(MsgPtr);
};

using MsgHandlerPtr = std::shared_ptr<MsgHandler>;
