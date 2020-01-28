#include "msghandler.h"

MsgHandler::MsgHandler(const std::string& msg,
                       ShipsListHandlerPtr shipsListHandlerPtr) :
    msg(msg),
    shipsListHandlerPtr(shipsListHandlerPtr)
{
    std::string initMsg = game::message::CONFIG_STATE;
    this->setConfigMsg(initMsg, type::name::DESTROYER);
    this->msg = initMsg;
}

void MsgHandler::print(const state& gameState) const
{
    std::cout << this->msg << std::endl;
}

void MsgHandler::onInputUpdate(const std::string& input)
{
    this->input = input;
}

void MsgHandler::onGameStateUpdate(const game::state& gameState)
{
    std::string msg;
    const bool noneMaxNumSet = this->shipsListHandlerPtr->noneMaxNumSet();
    const bool onlyFirstMaxNumSet = this->shipsListHandlerPtr->onlyFirstMaxNumSet();
    const bool onlyTwoFirstMaxNumSet = this->shipsListHandlerPtr->onlyTwoFirstMaxNumSet();
    const bool onlyThreeFirstMaxNumSet = this->shipsListHandlerPtr->onlyThreeFirstMaxNumSet();
    const bool onlyFourFirstMaxNumSet = this->shipsListHandlerPtr->onlyFourFirstMaxNumSet();

    switch (gameState)
    {
    case game::state::CONFIG:
        msg.append(message::CONFIG_STATE);
        if (noneMaxNumSet)
        {
            this->setConfigMsg(msg, type::name::DESTROYER);
        }
        else if (onlyFirstMaxNumSet)
        {
            this->setConfigMsg(msg, type::name::SUBMARINE);
        }
        else if (onlyTwoFirstMaxNumSet)
        {
            this->setConfigMsg(msg, type::name::CRUISER);
        }
        else if (onlyThreeFirstMaxNumSet)
        {
            this->setConfigMsg(msg, type::name::BATTLESHIP);
        }
        else if (onlyFourFirstMaxNumSet)
        {
            this->setConfigMsg(msg, type::name::CARRIER);
        }
        break;
    case game::state::DEPLOYMENT:
        // @TODO
        break;
    case game::state::BATTLE:
        // @TODO
        break;
    case game::state::END:

        break;
    default:
        break;
    }
    this->msg = msg;
}

void MsgHandler::setConfigMsg(std::string& msg, std::string typeName)
{
    unsigned int typeLen = type::functions::GET_TYPE_LEN(typeName);
    msg.append(message::TYPE_NUM_ADDITION_PART1 +
               typeName +
               message::TYPE_NUM_ADDITION_PART2 +
               std::to_string(typeLen) +
               message::TYPE_NUM_ADDITION_PART3);
}
