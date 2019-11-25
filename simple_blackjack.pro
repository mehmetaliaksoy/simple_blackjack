TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    abstractplayer.cpp \
    card.cpp \
    dealer.cpp \
    deck.cpp \
    game.cpp \
    main.cpp \
    simpleplayer.cpp

HEADERS += \
    abstractplayer.h \
    card.h \
    dealer.h \
    deck.h \
    game.h \
    simpleplayer.h
