#pragma once

#include "msghandler.h"
#include "gamestatehandler.h"
#include "observer.h"
#include "iprintable.h"


class MsgController :
        protected MsgHandler,
        private GameStateHandler,
        public IPrintable,
        public Observer
{
private:
    void setMsgPtr(const std::string&);
    MsgPtr getMsgPtr() const;

    const game::state& getGameState() const;

public:
    MsgController(MsgPtr, GameStatePtr);
    void print() const override;
    void onUpdate(const std::string&) override;
};

using MsgControllerPtr = std::shared_ptr<MsgController>;
