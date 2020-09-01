cmake_minimum_required(VERSION 3.13)


project("walletManager")
add_executable("walletManager" "main.cpp" "walletManager.cpp" "walletManager.h")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic
)
