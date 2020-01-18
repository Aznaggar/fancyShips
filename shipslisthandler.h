#pragma once
#include <array>

#include "inputobserver.h"
#include "gamestateobserver.h"
#include "ship.h"
#include "board.h"

using namespace game::ship::type;
using ShipTypeMaxNumsArray = std::array<unsigned int, maxnum::array::LENGTH>;

class ShipsListHandler :
        public InputObserver,
        public GameStateObserver
{
private:
    ShipTypeMaxNumsArray shipTypeMaxNumsArray;
    ShipsListPtr shipsListPtr;
    BoardPtr boardPtr;

    std::string input;

    const std::list<Ship>& getShipsList() const;
    const Board& getBoard() const;

    void setShipListPtr(const std::list<Ship>&);
    bool inputEquals(const std::string&);

    //CONFIG
    void initShipTypeMaxNumsArray();
    unsigned int getMaxTypeNum(const std::string&) const;
    bool isMaxNumSet(const std::string&) const;

    void setShipTypeMaxNum(const std::string&);

    bool isNameInDefaultTypes(const std::string& name) const;
    bool isLenInDefaultTypes(const int len) const;

    std::string getDefaultName(const int len) const;
    int getDefaultLen(const std::string& name) const;


    //DEPLOYMENT
    void addShip(const Ship&);

    bool areShipsAdjacent(const Ship&, const Ship&) const;
    bool areShipsColliding(const Ship&, const Ship&) const;

    bool isAdjacent(const Ship&) const;
    bool isColliding(const Ship&) const;

    bool isShipVerified(const Ship& ship) const;

    bool isTypeDeployed(const std::string&) const;

    void rearrangeShipsList();
public:
    ShipsListHandler(ShipsListPtr,
                     BoardPtr);
    ~ShipsListHandler();

    void onInputUpdate(const std::string&) override;
    void onGameStateUpdate(const game::state&) override;

    // StateGameProvider
    bool allMaxNumSet() const;
    bool allShipsDeployed() const;
    bool allShipsSunk() const;

    // MsgHandler
    bool noneMaxNumSet() const;
    bool onlyFirstMaxNumSet() const;
    bool onlyTwoFirstMaxNumSet() const;
    bool onlyThreeFirstMaxNumSet() const;
    bool onlyFourFirstMaxNumSet() const;



};

using ShipsListHandlerPtr = std::shared_ptr<ShipsListHandler>;
