#pragma once
#include <memory>

#include "boardhandler.h"
#include "shipslisthandler.h"
#include "gamestatehandler.h"
#include "iprintable.h"
#include "observer.h"

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

class BoardController :
        protected BoardHandler,
        private ShipsListHandler,
        private GameStateHandler,
        public IPrintable,
        public Observer
{
private:
    void printEmpty() const;
    void printNonEmpty() const;
    void printBattle() const;

    BoardPtr getBoardPtr() const;
    std::list<Ship> getShipsListCopy();
    game::state getGameStateCopy();

public:
    BoardController(BoardPtr,
                    ShipsListPtr,
                    GameStatePtr);

    void print() const override;
    void onUpdate(const std::string&) override;

};

using BoardControllerPtr = std::shared_ptr<BoardController>;
