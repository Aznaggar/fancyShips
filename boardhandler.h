#pragma once

#include "board.h"
#include "iprintable.h"
#include "inputobserver.h"
#include "shipslisthandler.h"
#include "gamestateobserver.h"

namespace game
{
    namespace board
    {
        namespace sign
        {
            const char EMPTY = '.';
            const char MAST = '$';
            const char HIDDEN = '*';
            const char HIT = 'x';
        }
    }
}

using namespace game;

class BoardHandler :
        public IPrintable,
        public InputObserver,
        public GameStateObserver
{
private:
    BoardPtr boardPtr;
    ShipsListPtr shipsListPtr;

    std::string input;

    const Board& getBoard() const;
    const std::list<Ship>& getShipsList() const;

    void printEmpty() const;
    void printNonEmpty() const;
    void printBattle() const;
public:
    BoardHandler(BoardPtr,
                 ShipsListPtr);
    ~BoardHandler();

    void print() const override;
    void onInputUpdate(const std::string&) override;
    void onGameStateUpdate(const game::state&) override;
};

using BoardHandlerPtr = std::shared_ptr<BoardHandler>;
