#include "referenceOrPointer.h"

int main() {
    int a = 2;
    int b = 3;
    int *c = &a;

    multiplyByPointer(c, b);
    multiplyByReference(a, b);
    return 0;
}
