cmake_minimum_required(VERSION 3.10)


project(CMakeProject1)



set(CMAKE_CXX_STANDARD 17)


add_executable(CMakeProject1 "Cvicení 10.cpp" "Cviceni 10.h")


configure_file(vstup.txt vstup.txt COPYONLY)