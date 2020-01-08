#include "msghandler.h"

MsgHandler::MsgHandler(const std::string& msg,
                       GameStatePtr gameStatePtr) :
    msg(msg),
    gameStatePtr(gameStatePtr) {}

MsgHandler::~MsgHandler()
{
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

const std::string& MsgHandler::getMsg() const
{
    return this->msg;
}

const game::state& MsgHandler::getGameState() const
{
    return *this->gameStatePtr;
}

void MsgHandler::setMsg(const std::string& msg)
{
    this->msg = msg;
}
