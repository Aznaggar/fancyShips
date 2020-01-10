#pragma once
#include <iostream>

#include "inputsubject.h"
#include "gamestateprovider.h"
#include "boardhandler.h"
#include "shipslisthandler.h"
#include "shotslisthandler.h"
#include "msghandler.h"

class InputHandler : public InputSubject
{
private:
    std::string input;
public:
    void getObservers(GameStateProviderPtr,
                      BoardHandlerPtr,
                      ShipsListHandlerPtr,
                      ShotsListHandlerPtr);
    void readInput();
    void parseInput();
    void updateInput();
};

using InputHandlerPtr = std::shared_ptr<InputHandler>;
