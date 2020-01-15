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
            namespace lenght
            {
                const unsigned int CARRIER = 5;
                const unsigned int BATTLESHIP = 4;
                const unsigned int CRUISER = 3;
                const unsigned int SUBMARINE = 2;
                const unsigned int DESTROYER = 1;
            }
            namespace maxnum
            {
                namespace value
                {
                    const unsigned int CARRIER = 1;
                    const unsigned int BATTLESHIP = 2;
                    const unsigned int CRUISER = 3;
                    const unsigned int SUBMARINE = 4;
                    const unsigned int DESTROYER = 5;
                }
                namespace arrayindex
                {
                    const unsigned int CARRIER = 0;
                    const unsigned int BATTLESHIP = 1;
                    const unsigned int CRUISER = 2;
                    const unsigned int SUBMARINE = 3;
                    const unsigned int DESTROYER = 4;
                }
            }
            const unsigned int TYPES_NUM = 5;
            namespace functions
            {
                inline unsigned int GET_TYPE_LEN(const std::string& name)
                {
                    if (name == name::DESTROYER)
                    {
                        return lenght::DESTROYER;
                    } else if (name == name::SUBMARINE)
                    {
                        return lenght::SUBMARINE;
                    } else if (name == name::CRUISER)
                    {
                        return lenght::CRUISER;
                    } else if (name == name::BATTLESHIP)
                    {
                        return lenght::BATTLESHIP;
                    } else if (name == name::CARRIER)
                    {
                        return lenght::CARRIER;
                    } else
                    {
                        return 0;
                    }
                }

                inline unsigned int GET_ARRAY_INDEX(const std::string& name)
                {
                    if (name == name::DESTROYER)
                    {
                        return maxnum::arrayindex::DESTROYER;
                    } else if (name == name::SUBMARINE)
                    {
                        return maxnum::arrayindex::SUBMARINE;
                    } else if (name == name::CRUISER)
                    {
                        return maxnum::arrayindex::CRUISER;
                    } else if (name == name::BATTLESHIP)
                    {
                        return maxnum::arrayindex::BATTLESHIP;
                    } else if (name == name::CARRIER)
                    {
                        return maxnum::arrayindex::CARRIER;
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
