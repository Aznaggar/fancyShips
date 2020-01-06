#include "configcontroller.h"
#include <iostream>

ConfigController::ConfigController(ConfigsListPtr configsListPtr,
                                   GameStatePtr gameStatePtr) :
    ConfigsListHandler(configsListPtr),
    GameStateHandler(gameStatePtr) {}

void ConfigController::onUpdate(const std::string& input)
{
    //@TODO
}

void ConfigController::addConfig(const Config &config)
{
    ConfigsListHandler::addConfig(config);
}

ConfigsListPtr ConfigController::getConfigsListPtr() const
{
    return ConfigsListHandler::getConfigsListPtr();
}

const game::state& ConfigController::getGameState() const
{
    return *GameStateHandler::getGameStatePtr();
}
