#pragma once

#include "board.h"
#include "iprintable.h"
#include "observer.h"
#include "shipslisthandler.h"
#include "gamestatehandler.h"

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
        public Observer
{
private:
    BoardPtr boardPtr;
    ShipsListPtr shipsListPtr;
    GameStatePtr gameStatePtr;

    const Board& getBoard() const;
    const std::list<Ship>& getShipsList() const;
    const game::state& getGameState() const;

    void printEmpty() const;
    void printNonEmpty() const;
    void printBattle() const;
public:
    BoardHandler(BoardPtr,
                 ShipsListPtr,
                 GameStatePtr);
    ~BoardHandler();

    void print() const override;
    void onUpdate(const std::string&) override;    
};

using BoardHandlerPtr = std::shared_ptr<BoardHandler>;
