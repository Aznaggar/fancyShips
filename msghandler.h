#pragma once
#include <memory>

#include "inputobserver.h"
#include "gamestateobserver.h"
#include "inputobserver.h"
#include "iprintable.h"
#include "shipslisthandler.h"

namespace game
{
  namespace message
  {
    const std::string INVALID_OPTION = "Invalid option chosen. ";
    const std::string INVALID_INPUT = "Invalid input given. ";

    const std::string CONFIG_STATE = "Configuration phase. ";
    const std::string TYPE_NUM_ADDITION_PART1 = "Set max number of ";
    const std::string TYPE_NUM_ADDITION_PART2 = "s (";
    const std::string TYPE_NUM_ADDITION_PART3 = " mast(s))";

    const std::string DEPLOYMENT_CHOICE = "Manual / automatic deployment?(m/a): ";
  }
}

using namespace game::message;
using namespace game::shiptype;

class MsgHandler :
        public GameStateObserver,
        public InputObserver,
        public IPrintable
{
private:
    std::string msg;
    std::string input;

    ShipsListHandlerPtr shipsListHandlerPtr;

    void setConfigMsg(std::string&,
                      std::string);

public:
    MsgHandler(const std::string&,
               ShipsListHandlerPtr);

    void print() const override;
    void onGameStateUpdate(const game::state&) override;
    void onInputUpdate(const std::string& input) override;
};

using MsgHandlerPtr = std::shared_ptr<MsgHandler>;
