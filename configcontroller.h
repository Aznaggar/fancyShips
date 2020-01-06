#pragma once
#include <memory>

#include "configslisthandler.h"
#include "gamestatehandler.h"
#include "observer.h"


class ConfigController :
        protected ConfigsListHandler,
        private GameStateHandler,
        public Observer
{
private:
    void addConfig(const Config &);
    ConfigsListPtr getConfigsListPtr() const;
    const game::state& getGameState() const;
public:
    ConfigController(ConfigsListPtr, GameStatePtr);

    void onUpdate(const std::string&) override;

};

using ConfigControllerPtr = std::shared_ptr<ConfigController>;
