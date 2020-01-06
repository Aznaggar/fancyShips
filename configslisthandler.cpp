#include "configslisthandler.h"

ConfigsListHandler::ConfigsListHandler(ConfigsListPtr configsListPtr) :
    configsListPtr(configsListPtr) {}

ConfigsListHandler::~ConfigsListHandler()
{
    this->configsListPtr.reset();
}

ConfigsListPtr ConfigsListHandler::getConfigsListPtr() const
{
    return this->configsListPtr;
}

void ConfigsListHandler::addConfig(const Config& config)
{
    this->configsListPtr->push_back(config);
}
