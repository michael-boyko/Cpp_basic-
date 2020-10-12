#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<std::string> v_str;
    std::vector<std::string> v_names {"mercer", "emer", "jim"};
    std::string tmp;

    if (argc == 1) {
        std::cout << "usage: ./moveAlong [args]" << std::endl;
    } else {
        for (int j = 1; j < argc; j++) {
            tmp.clear();
            for (int i = 0; argv[j][i] != '\0'; i++) {
                tmp += tolower(argv[j][i]);
            }
            v_str.push_back(tmp);
        }
        for (int i = 0; i < argc - 1; i++) {
            for (int j = 0; j < 3; j++) {
                if (v_str[i].find(v_names[j]) != std::string::npos) {
                    std::cout << v_str[i] + ", move along!" << std::endl;
                }
            }
        }
    }
// system("leaks -q moveAlong");
    return 0;
}
