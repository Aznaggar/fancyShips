#include "msghandler.h"

MsgHandler::MsgHandler(const std::string& msg,
                       ShipsListHandlerPtr shipsListHandlerPtr) :
    msg(msg),
    shipsListHandlerPtr(shipsListHandlerPtr) {}

void MsgHandler::print() const
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
//        switch (this->input)
//        {
//            onError
//        }
        if (noneMaxNumSet)
        {
            this->setConfigMsg(msg, shiptype::name::DESTROYER);
        }
        else if (onlyFirstMaxNumSet)
        {
            this->setConfigMsg(msg, shiptype::name::SUBMARINE);
        }
        else if (onlyTwoFirstMaxNumSet)
        {
            this->setConfigMsg(msg, shiptype::name::CRUISER);
        }
        else if (onlyThreeFirstMaxNumSet)
        {
            this->setConfigMsg(msg, shiptype::name::BATTLESHIP);
        }
        else if (onlyFourFirstMaxNumSet)
        {
            this->setConfigMsg(msg, shiptype::name::CARRIER);
        }
    case game::state::DEPLOYMENT:

        break;
    case game::state::BATTLE:

        break;
    case game::state::END:

        break;
    default:
        break;
    }
}

void MsgHandler::setConfigMsg(std::string& msg, std::string shipTypeName)
{
    unsigned int shipTypeLen = shiptype::Functions::getTypeLen(shipTypeName);
    msg.append(message::TYPE_NUM_ADDITION_PART1 +
               shipTypeName +
               message::TYPE_NUM_ADDITION_PART2 +
               std::to_string(shipTypeLen) +
               message::TYPE_NUM_ADDITION_PART3);
}
