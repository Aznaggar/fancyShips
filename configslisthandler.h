#pragma once

#include <list>

#include "shiptypeconfig.h"
#include "gamestatehandler.h"
#include "observer.h"

class ConfigsListHandler : public Observer
{
private:
    ConfigsListPtr configsListPtr;
    GameStatePtr gameStatePtr;

    ConfigsListPtr getConfigsListPtr() const;
    void addConfig(const Config&);
public:
    ConfigsListHandler(ConfigsListPtr,
                       GameStatePtr);
    ~ConfigsListHandler();

    void onUpdate(const std::string&) override;

};

using ConfigsListHandlerPtr = std::shared_ptr<ConfigsListHandler>;
