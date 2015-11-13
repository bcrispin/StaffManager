cmake_minimum_required(VERSION 3.3)
project(StaffManager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp model/Person.cpp model/Person.h PersonManager.cpp PersonManager.h PersonManagerInterface.cpp PersonManagerInterface.h model/Staff.cpp model/Staff.h model/Faculty.cpp model/Faculty.h)
add_executable(StaffManager ${SOURCE_FILES})