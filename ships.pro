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
    deploymentcontroller.cpp \
    battlecontroller.cpp \
    boardcontroller.cpp \
    subject.cpp \
    inputhandler.cpp \
    msgcontroller.cpp

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
    deploymentcontroller.h \
    iprintable.h \
    battlecontroller.h \
    boardcontroller.h \
    observer.h \
    subject.h \
    inputhandler.h \
    msgcontroller.h \
    gameconstants.h
