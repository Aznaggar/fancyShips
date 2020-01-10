#pragma once
#include <string>

namespace game
{
    namespace shiptype
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
        class Functions
        {
        private:
            Functions()                      = delete;
            Functions(Functions const&)      = delete;
            void operator=(Functions const&) = delete;
        public:
            static unsigned int getTypeLen(const std::string&);
            static unsigned int getArrayIndex(const std::string&);
        };
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
