cmake_minimum_required(VERSION 3.13)


project("castSpells")
add_executable("castSpells" "main.cpp" "castSpells.cpp" "castSpells.h")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
