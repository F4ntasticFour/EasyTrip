cmake_minimum_required(VERSION 3.26)
project(EasyTrip)

set(CMAKE_CXX_STANDARD 17)

add_executable(EasyTrip main.cpp
        EventClass.cpp
        EventClass.h
        PassengerClass.cpp
        PassengerClass.h
        BusClass.cpp
        BusClass.h
        CompanyClass.cpp
        CompanyClass.h
        Station.cpp
        Station.h
        UiClass.cpp
        UiClass.h
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h
        Node.cpp
        Node.h
        PriorityQueue.cpp
        PriorityQueue.h
        LinkedList.cpp
        LinkedList.h)
