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
        StationClass.cpp
        StationClass.h
        UiClass.cpp
        UiClass.h
        Stack.impl
        Stack.h
        Queue.impl
        Queue.h
        Node.impl
        Node.h
        PriorityQueue.impl
        PriorityQueue.h
<<<<<<< HEAD
        LinkedList.impl
        LinkedList.h
        MixedBusClass.cpp
        NormalPassengerClass.h
        SpecialCategoryPassengerClass.h
        WheelChairBusClass.cpp
        WheelChairPassengerClass.cpp
        TimeClass.cpp
        TimeClass.h)

=======
        LinkedList.cpp
        LinkedList.h
        TimeClass.cpp
        TimeClass.h
        MixedBusClass.cpp
        MixedBusClass.h
        WheelChairBusClass.cpp
        WheelChairBusClass.h
        SpecialCategoryPassengerClass.cpp
        SpecialCategoryPassengerClass.h
        NormalPassengerClass.cpp
        NormalPassengerClass.h
        WheelChairPassengerClass.cpp
        WheelChairPassengerClass.h)
>>>>>>> 4884c76 (add derived classes WCP, SCP, NP Passengers and WCB, MB.)
