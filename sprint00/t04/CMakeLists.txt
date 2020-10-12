cmake_minimum_required(VERSION 3.13)


project("referenceOrPointer")
add_executable("referenceOrPointer" "main.cpp" "referenceOrPointer.h" "referenceOrPointer.cpp")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
