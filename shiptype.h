#pragma once
#include <string>

namespace game
{
    namespace ship
    {
        namespace type
        {
            namespace name
            {
                const std::string CARRIER = "Carrier";
                const std::string BATTLESHIP = "Battleship";
                const std::string CRUISER = "Cruiser";
                const std::string SUBMARINE = "Submarine";
                const std::string DESTROYER = "Destroyer";
            }
            enum length : unsigned int
            {
                CARRIER = 5,
                BATTLESHIP = 4,
                CRUISER = 3,
                SUBMARINE = 2,
                DESTROYER = 1
            };
            namespace maxnum
            {
                enum value : unsigned int
                {
                    CARRIER = 1,
                    BATTLESHIP,
                    CRUISER,
                    SUBMARINE,
                    DESTROYER
                };
                namespace array
                {
                    enum index : unsigned int
                    {
                        CARRIER = 0,
                        BATTLESHIP,
                        CRUISER,
                        SUBMARINE,
                        DESTROYER
                    };
                    const unsigned int LENGTH = 5;
                }
            }
            namespace functions
            {
                inline unsigned int GET_TYPE_LEN(const std::string& name)
                {
                    if (name == name::DESTROYER)
                    {
                        return length::DESTROYER;
                    } else if (name == name::SUBMARINE)
                    {
                        return length::SUBMARINE;
                    } else if (name == name::CRUISER)
                    {
                        return length::CRUISER;
                    } else if (name == name::BATTLESHIP)
                    {
                        return length::BATTLESHIP;
                    } else if (name == name::CARRIER)
                    {
                        return length::CARRIER;
                    } else
                    {
                        return 0;
                    }
                }

                inline int GET_ARRAY_INDEX(const std::string& name)
                {
                    if (name == name::DESTROYER)
                    {
                        return maxnum::array::index::DESTROYER;
                    } else if (name == name::SUBMARINE)
                    {
                        return maxnum::array::index::SUBMARINE;
                    } else if (name == name::CRUISER)
                    {
                        return maxnum::array::index::CRUISER;
                    } else if (name == name::BATTLESHIP)
                    {
                        return maxnum::array::index::BATTLESHIP;
                    } else if (name == name::CARRIER)
                    {
                        return maxnum::array::index::CARRIER;
                    } else
                    {
                        return -1;
                    }
                }
            }
        }
    }
}

using namespace game;

class ShipType
{
private:
    std::string name;
    unsigned int len;

public:
    ShipType(const std::string&, const unsigned int);
    unsigned int getLen() const;
    const std::string& getName() const;
};
