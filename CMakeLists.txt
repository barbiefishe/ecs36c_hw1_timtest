cmake_minimum_required(VERSION 3.15)
project(ecs36c_hw1_timtest)

set(CMAKE_CXX_STANDARD 14)

add_executable(ecs36c_hw1_timtest main.cpp CPUTimer.h
                                    CursorList.h CursorList.cpp
                                    dsexceptions.h filecreate.cpp
                                    LinkedList.h LinkedList.cpp
                                    QueueAr.h QueueAr.cpp
                                    QueueLL.h QueueLL.cpp
                                    SkipList.h SkipList.cpp
                                    StackAr.h StackAr.cpp
                                    StackLi.h StackLi.cpp
                                    vector.h vector.cpp)