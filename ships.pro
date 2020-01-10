TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shiptype.cpp \
    position.cpp \
    board.cpp \
    mast.cpp \
    ship.cpp \
    shipslisthandler.cpp \
    game.cpp \
    inputhandler.cpp \
    shotslisthandler.cpp \
    boardhandler.cpp \
    msghandler.cpp \
    inputsubject.cpp \
    gamestatesubject.cpp \
    gamestateprovider.cpp

HEADERS += \
    shiptype.h \
    position.h \
    board.h \
    mast.h \
    ship.h \
    shipslisthandler.h \
    game.h \
    iprintable.h \
    inputhandler.h \
    gameconstants.h \
    shotslisthandler.h \
    boardhandler.h \
    msghandler.h \
    inputobserver.h \
    inputsubject.h \
    gamestateobserver.h \
    gamestatesubject.h \
    gamestateprovider.h
