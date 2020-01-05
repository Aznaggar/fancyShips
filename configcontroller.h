#pragma once
#include <memory>

#include "configslisthandler.h"
#include "observer.h"


class ConfigController :
        protected ConfigsListHandler,
        public Observer
{
public:
    ConfigController(ConfigsListPtr);
};

using ConfigControllerPtr = std::shared_ptr<ConfigController>;
