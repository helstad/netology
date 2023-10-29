cmake_minimum_required(VERSION 3.26)
project(fantasy_race)

set(CMAKE_CXX_STANDARD 20)

add_executable(fantasy_race main.cpp
        RaceDLL/Entity.cpp
        RaceDLL/Entity.h
        RaceDLL/GroundEntity.cpp
        RaceDLL/GroundEntity.h
        RaceDLL/AirEntity.cpp
        RaceDLL/AirEntity.h
        RaceDLL/Camel.cpp
        RaceDLL/Camel.h
        RaceDLL/FastCamel.cpp
        RaceDLL/FastCamel.h
        RaceDLL/Centaur.cpp
        RaceDLL/Centaur.h
        RaceDLL/BootsTerrain.cpp
        RaceDLL/BootsTerrain.h
        RaceManager.cpp
        RaceManager.h
        RaceDLL/EntitiesList.h
)
