#include "game.h"

int main()
{
    Game game;
    InputHandlerPtr inputHandlerPtr = std::make_shared<InputHandler>();
    game.run(inputHandlerPtr);
    while(game.isRunning())
    {
        game.printGame();
        inputHandlerPtr->readInput();
        game.updateGame(inputHandlerPtr);
    }
}
