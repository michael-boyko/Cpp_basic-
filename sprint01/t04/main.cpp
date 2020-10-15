#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <forward_list>

int main(int argc, char *argv[]) {
    std::ifstream fin;
    std::string str;
    std::forward_list<std::string> vstr;
    int list_size = 0;
    bool r = 0;
    bool s = 0;
    int vel = 0;
    int mel = 0;
    
    if (argc != 2) {
        std::cout << "usage: ./stdAlgoV1 [file_name]" << std::endl;
        exit(0);
    }
    fin.open(argv[1]);
    if (!fin.is_open()) {
        std::cout << "error" << std::endl;
    } else {
        while (getline(fin, str, '\n')) {
            if (str.find("rich") == std::string::npos) {
                r = 1;
            }
            if (str.size() > 15) {
                s = 0;
            }
            if (str.rfind("vel") == std::string::npos) {
                vel++;
            }
            if (str.find("mel") == std::string::npos) {
                mel++;
            }
            vstr.push_front(str);
            list_size++;
        }
        std::cout << "size: " << list_size << std::endl;
        std::cout << "contains 'rich': " << (r == 0 ? "false" : "true") << std::endl;
        std::cout << "none of lengths is 15: " << (s == 0 ? "false" : "true") << std::endl;
        std::cout << "all end with 'vel': " << (vel != list_size ? "false" : "true") << std::endl;
        std::cout << "not contains 'mel': " << mel << std::endl;
    }

    return 0;
}












