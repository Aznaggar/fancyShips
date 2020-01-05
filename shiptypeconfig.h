#pragma once

#include "shipType.h"

namespace shiptypeconfig
{
    const std::list<ShipType> SHIP_TYPE_LIST = {
        ShipType(shiptype::name::CARRIER, shiptype::lenght::CARRIER),
        ShipType(shiptype::name::BATTLESHIP, shiptype::lenght::BATTLESHIP),
        ShipType(shiptype::name::CRUISER, shiptype::lenght::CRUISER),
        ShipType(shiptype::name::SUBMARINE, shiptype::lenght::SUBMARINE),
        ShipType(shiptype::name::DESTROYER, shiptype::lenght::DESTROYER)
    };
    namespace maxnumdefault
    {
        const unsigned int CARRIER = 1;
        const unsigned int BATTLESHIP = 2;
        const unsigned int CRUISER = 3;
        const unsigned int SUBMARINE = 4;
        const unsigned int DESTROYER = 5;
    }
}

class ShipTypeConfig
{
private:
    ShipType type;
    int typeCounter;
    int maxTypeNum;

public:
    ShipTypeConfig(const ShipType& type, const int maxTypeNum);
    void incrementTypeCounter();
    bool isTypeFullyDeployed() const;
    const ShipType& getType() const;
};
