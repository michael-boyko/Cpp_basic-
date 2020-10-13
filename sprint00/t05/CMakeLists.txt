cmake_minimum_required(VERSION 3.13)


project("Automaton")
add_executable("Automaton" "main.cpp")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
