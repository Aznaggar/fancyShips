#include "boardhandler.h"

BoardHandler::BoardHandler(BoardPtr boardPtr) : boardPtr(boardPtr) {}

BoardHandler::~BoardHandler() { this->boardPtr.reset(); }

BoardPtr BoardHandler::getBoardPtr() const { return this->boardPtr; }
