cmake_minimum_required(VERSION 3.3)
project(StaffManager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Person.cpp Person.h PersonInterface.cpp PersonInterface.h PersonManager.cpp PersonManager.h PersonManagerInterface.cpp PersonManagerInterface.h Staff.cpp Staff.h StaffInterface.cpp StaffInterface.h)
add_executable(StaffManager ${SOURCE_FILES})