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
    configcontroller.cpp \
    boardcontroller.cpp \
    subject.cpp \
    inputhandler.cpp \
    msgcontroller.cpp \
    gamestatecontroller.cpp \
    gamestatehandler.cpp \
    shipslistcontroller.cpp \
    shotslistcontroller.cpp \
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
    configcontroller.h \
    iprintable.h \
    boardcontroller.h \
    observer.h \
    subject.h \
    inputhandler.h \
    msgcontroller.h \
    gameconstants.h \
    gamestatecontroller.h \
    gamestatehandler.h \
    shipslistcontroller.h \
    shotslistcontroller.h \
    shotslisthandler.h \
    boardhandler.h \
    msghandler.h
