cmake_minimum_required(VERSION 3.13)


project("hello_world")
add_executable("hello" "hello_world.cpp")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
