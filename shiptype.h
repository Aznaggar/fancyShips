#pragma once
#include <string>
#include <list>

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
    const int CARRIER = 5;
    const int BATTLESHIP = 4;
    const int CRUISER = 3;
    const int SUBMARINE = 2;
    const int DESTROYER = 1;
  }
}

class ShipType
{
private:
    std::string name;
    int len;

    bool isNameInDefaultTypes(const std::string& name) const;
    bool isLenInDefaultTypes(const int len) const;

    std::string getDefaultName(const int len) const;
    int getDefaultLen(const std::string& name) const;

public:
    ShipType(const std::string& name, const int len);
    int getLen() const;
    const std::string& getName() const;
};
