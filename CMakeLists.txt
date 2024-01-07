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
        StationClass.cpp
        StationClass.h
        UiClass.cpp
        UiClass.h
        Stack.h
        Queue.h
        Node.h
        PriorityQueue.h
        LinkedList.h
        TimeClass.cpp
        TimeClass.h
        CompanyClass.h
        FileHandler.cpp
        FileHandler.h
        NodeP.h
)


