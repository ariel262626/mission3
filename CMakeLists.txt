cmake_minimum_required(VERSION 3.5)
project(MISSION3)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES main.cpp Matrix2d.cpp
        Matrix2d.h Grid.cpp Grid.h Bfs.cpp Bfs.h Node.cpp Node.h Point.cpp Point.h Driver.cpp Driver.h StandartCab.cpp
        StandartCab.h
        LuxuryCab.cpp LuxuryCab.h Trip.cpp Trip.h Passenger.cpp Passenger.h
        InfoTaxi.cpp InfoTaxi.h TexiCenter.cpp TexiCenter.h TestPoint.cpp TestMatrix2d.cpp
        PassengerTest.cpp TestDriver.cpp TestTrip.cpp TestCabBase.cpp GameFlow.cpp GameFlow.h
        TestTexiCenter.cpp TestBfs.cpp TestNode.cpp CabBase.h CabBase.cpp PharserInfo.cpp PharserInfo.h TestParser.cpp)

add_executable(MISSION3 ${SOURCE_FILES})
target_link_libraries(MISSION3 gtest gtest_main)
