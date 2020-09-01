cmake_minimum_required(VERSION 3.13)


project("printDialog")
add_executable("printDialog" "main.cpp" "printDialog.cpp" "printDialog.h")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
