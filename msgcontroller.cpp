#include "msgcontroller.h"

MsgController::MsgController(MsgPtr msgPtr,
                             GameStatePtr gameStatePtr) :
    MsgHandler(msgPtr),
    GameStateHandler(gameStatePtr) {}

void MsgController::print() const
{
    //@TODO
}

void MsgController::onUpdate(const std::string& input)
{
    //@TODO
}

void MsgController::setMsgPtr(const std::string& msg)
{
    MsgHandler::setMsgPtr(msg);
}

MsgPtr MsgController::getMsgPtr() const
{
    return MsgHandler::getMsgPtr();
}

const game::state& MsgController::getGameState() const
{
    return *GameStateHandler::getGameStatePtr();
}
