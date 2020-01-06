#include "msghandler.h"

MsgHandler::MsgHandler(MsgPtr msgPtr) : msgPtr(msgPtr) {}

MsgHandler::~MsgHandler() { this->msgPtr.reset();}

void MsgHandler::setMsgPtr(const std::string& msg)
{
    this->msgPtr = std::make_shared<std::string>(msg);
}

void MsgHandler::setMsgPtr(MsgPtr msgPtr)
{
    this->msgPtr = msgPtr;
}

MsgPtr MsgHandler::getMsgPtr() const { return this->msgPtr; }
