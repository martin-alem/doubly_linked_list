cmake_minimum_required(VERSION 3.18)
project(doubly_linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(doubly_linked_list main.c doubly_linked_list.h doubly_linked_list.c)