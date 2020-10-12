#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::array<std::string, 5> arr;
    
    if (argc != 6) {
        std::cout << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << std::endl;
    } else {
        for (int i = 0; i < 5; i++) {
            arr[i] = argv[i + 1];
        }
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < 4; ++i) {
            std::cout << arr[i] + " ";
        }
        std::cout << arr[4] << std::endl;
    }

	return 0;
}
