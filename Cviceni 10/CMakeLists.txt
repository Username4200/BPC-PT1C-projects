cmake_minimum_required(VERSION 3.10)


project(Cviceni10 C)

set(CMAKE_C_STANDARD 99)


add_executable(Cviceni10 "Cviceni 10.cpp" "Cviceni 10.h")


configure_file("vstup.txt" "vstup.txt" COPYONLY)