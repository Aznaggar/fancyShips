#include "shotslisthandler.h"

ShotsListHandler::ShotsListHandler(ShotsListPtr shotsListPtr) :
    shotsListPtr(shotsListPtr) {}

ShotsListHandler::~ShotsListHandler()
{
    this->shotsListPtr.reset();
}

void ShotsListHandler::setShotsListPtr(ShotsListPtr shotsListPtr)
{
    this->shotsListPtr = shotsListPtr;
}

void ShotsListHandler::addShot(const battle::shot& shot)
{
    this->shotsListPtr->push_back(shot);
}

ShotsListPtr ShotsListHandler::getShotsListPtr() const
{
    return this->shotsListPtr;
}
