cmake_minimum_required(VERSION 3.23)
project(assignment1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(assignment1
        include/Agent.h
        include/Graph.h
        include/JoinPolicy.h
        include/json.hpp
        include/Parser.h
        include/Party.h
        include/SelectionPolicy.h
        include/Simulation.h
        src/EdgeWeightSelectionPolicy.cpp
        src/MandatesSelectionPolicy.cpp
        src/MandatesJoinPolicy.cpp
        src/LastOfferJoinPolicy.cpp
        src/Agent.cpp
        src/Graph.cpp
        src/main.cpp
        src/Parser.cpp
        src/Party.cpp
        src/Simulation.cpp
        tests/01.json
        tests/01_sol.out
        tests/02.json
        tests/02_sol.out
        tests/03.json
        tests/03_sol.out
        makefile
        visualization.py)
