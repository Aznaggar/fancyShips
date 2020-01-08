TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shiptype.cpp \
    shiptypeconfig.cpp \
    position.cpp \
    board.cpp \
    mast.cpp \
    ship.cpp \
    configslisthandler.cpp \
    shipslisthandler.cpp \
    game.cpp \
    subject.cpp \
    inputhandler.cpp \
    gamestatehandler.cpp \
    shotslisthandler.cpp \
    boardhandler.cpp \
    msghandler.cpp

HEADERS += \
    shiptype.h \
    shiptypeconfig.h \
    position.h \
    board.h \
    mast.h \
    ship.h \
    configslisthandler.h \
    shipslisthandler.h \
    game.h \
    iprintable.h \
    observer.h \
    subject.h \
    inputhandler.h \
    gameconstants.h \
    gamestatehandler.h \
    shotslisthandler.h \
    boardhandler.h \
    msghandler.h
