cmake_minimum_required(VERSION 3.10)
project(Lab_Polimorfizm)

set(CMAKE_CXX_STANDARD 11)

# Найти Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Lab3 unit.cpp Rombe.cpp Pentagon.cpp Hexagon.cpp Figure.cpp)

# Линковать с Google Test
target_link_libraries(Lab3 ${GTEST_LIBRARIES} pthread)

add_executable(main main.cpp Rombe.cpp Pentagon.cpp Hexagon.cpp Figure.cpp)
