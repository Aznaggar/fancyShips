#pragma once
#include <memory>
#include <list>

#include "shiptypeconfig.h"

using Config = ShipTypeConfig;
using ConfigsListPtr = std::shared_ptr<std::list<Config>>;

class ConfigsListHandler
{
private:
    ConfigsListPtr configsListPtr;
protected:
    void addConfig(const Config&);
public:
    ConfigsListHandler(ConfigsListPtr);
    virtual ~ConfigsListHandler();

    ConfigsListPtr getConfigsList() const;
};
