cmake_minimum_required(VERSION 3.16)
project(lab_2)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
)
FetchContent_MakeAvailable(googletest)

# Добавить пути для include
include_directories(include)
include_directories(src)

# Создание библиотеки
add_library(binary src/binary.cpp)

# Основной исполняемый файл
add_executable(lab_2_exe main.cpp)
target_link_libraries(lab_2_exe binary)

# Подключение Google Test
enable_testing()

# Тестовый исполняемый файл
add_executable(tests_lab2 tests/test_binary.cpp)
target_link_libraries(tests_lab2 binary gtest gtest_main)
add_test(NAME tests_lab2 COMMAND tests_lab2)