cmake_minimum_required(VERSION 3.3)
project(Project1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CommandProcessor.cpp Menu.cpp SingleNode.h  CyclicLinkedList.h DoubleNode.h DoublyLinkedList.h DoubleNode.h DoublyLinkedList.h)
add_executable(Project1 ${SOURCE_FILES}  Menu.h SingleNode.h  CyclicLinkedList.h CommandProcessor.h DoubleNode.h DoublyLinkedList.h)