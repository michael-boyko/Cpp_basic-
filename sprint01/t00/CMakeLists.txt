cmake_minimum_required(VERSION 3.13)


project("simpleSort")
add_executable("simpleSort" "main.cpp")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
