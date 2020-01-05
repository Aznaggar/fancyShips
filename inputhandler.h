#pragma once
#include <iostream>

#include "subject.h"
#include "game.h"

class InputHandler : public Subject
{
private:
    std::string input;
public:
    void getObservers(const Game&);
    void readInput();
    void parseInput();
    void updateGame();
};
