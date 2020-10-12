cmake_minimum_required(VERSION 3.13)


project("visitAll")
add_executable("visitAll" "main.cpp")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
