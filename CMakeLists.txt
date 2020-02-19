cmake_minimum_required(VERSION 3.13)
project(calendar)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

include_directories(googletest/googletest/include)

include_directories(googletest/googlemock/include)



add_executable(calendar main.cpp date.cpp CalendarTest.cpp)


target_link_libraries(calendar gtest gtest_main)