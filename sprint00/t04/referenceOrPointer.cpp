#include "referenceOrPointer.h"

void multiplyByPointer(int* ptr, int mult) {
    std::cout << (*ptr * mult) << std::endl;
}
void multiplyByReference(int& ref, int mult) {
    std::cout << (ref * mult) << std::endl;
}
