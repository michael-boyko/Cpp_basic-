#include "castSpells.h"


int main() {
	float a = 1.05;
	const int *b = NULL;

	std::cout << typeid(castFloatToInt(a)).name() << std::endl;
	std::cout << typeid(castToNonConstIntPtr(b)).name() << std::endl;
	return 0;
}