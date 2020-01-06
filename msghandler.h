#pragma once
#include <memory>
#include <string>

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

class MsgHandler
{
private:
    MsgPtr msgPtr;
protected:
    void setMsgPtr(const std::string&);
    void setMsgPtr(MsgPtr);
public:
    MsgHandler(MsgPtr);
    virtual ~MsgHandler();

    MsgPtr getMsgPtr() const;
};
