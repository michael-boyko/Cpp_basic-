cmake_minimum_required(VERSION 3.13)

project("CountUniqueWords")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)

add_executable("CountUniqueWords" "main.cpp")
