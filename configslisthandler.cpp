#include "configslisthandler.h"

ConfigsListHandler::ConfigsListHandler(ConfigsListPtr configsListPtr,
                                       GameStatePtr gameStatePtr) :
    configsListPtr(configsListPtr),
    gameStatePtr(gameStatePtr) {}

ConfigsListHandler::~ConfigsListHandler()
{
    this->configsListPtr.reset();
    this->gameStatePtr.reset();
}

void ConfigsListHandler::onUpdate(const std::string& input)
{
    //@TODO
}

const std::list<Config>& ConfigsListHandler::getConfigsList() const
{
    return *this->configsListPtr;
}

const game::state& ConfigsListHandler::getGameState() const
{
    return *this->gameStatePtr;
}

void ConfigsListHandler::addConfig(const Config& config)
{
    this->configsListPtr->push_back(config);
}
