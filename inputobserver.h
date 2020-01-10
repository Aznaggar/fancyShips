#pragma once
#include <string>

namespace game
{
    namespace commands
    {
        const std::string END_GAME = "q";
        const std::string DEPLOY_SHIP = "ds";
        const std::string FINISH_DEVELOPMENT = "fd";
        const std::string BOARD_RESIZE = "r";
        const std::string TAKE_SHOT = "s";
    }
}

class InputObserver
{
public:
    virtual ~InputObserver() {}
    virtual void onInputUpdate(const std::string&) = 0;
};
