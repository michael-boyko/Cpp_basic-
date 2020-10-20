cmake_minimum_required(VERSION 3.13)

project("OutputAny")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic
)

add_executable("outputAny" "main.cpp" "outputAny.h")
