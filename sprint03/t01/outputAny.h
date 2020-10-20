#pragma once
#include "iostream"

template <class Container>
void outputAny(const Container& c) {
    for (auto n : c) {
        std::cout << n << std::endl;
    }
}
