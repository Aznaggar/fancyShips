#include "msghandler.h"

MsgHandler::MsgHandler(MsgPtr msgPtr,
                       GameStatePtr gameStatePtr) :
    msgPtr(msgPtr),
    gameStatePtr(gameStatePtr) {}

MsgHandler::~MsgHandler()
{
    this->msgPtr.reset();
    this->gameStatePtr.reset();
}

void MsgHandler::print() const
{
    //@TODO
}

void MsgHandler::onUpdate(const std::string& input)
{
    //@TODO
}

void MsgHandler::setMsgPtr(const std::string& msg)
{
    this->msgPtr = std::make_shared<std::string>(msg);
}

void MsgHandler::setMsgPtr(MsgPtr msgPtr)
{
    this->msgPtr = msgPtr;
}

MsgPtr MsgHandler::getMsgPtr() const
{
    return this->msgPtr;
}

const std::string& MsgHandler::getMsg() const
{
    return *this->msgPtr;
}

const game::state& MsgHandler::getGameState() const
{
    return *this->gameStatePtr;
}

