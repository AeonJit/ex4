cmake_minimum_required(VERSION 3.20)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(Cards)
include_directories(Players)

add_executable(ex4
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Battle.cpp
        Cards/Battle.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Gremlin.cpp
        Cards/Gremlin.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Well.cpp
        Cards/Well.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Witch.cpp
        Cards/Witch.h
        Players/Warrior.cpp
        Players/Warrior.h
        Players/Player.cpp
        Players/Player.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Healer.cpp
        Players/Healer.h
        tool/main.cpp
        Exception.h
        Mtmchkin.cpp
        Mtmchkin.h
        utilities.cpp utilities.h)
