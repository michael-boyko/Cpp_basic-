#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <array>
#include <list>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <forward_list>



int main(int argc, char *argv[]) {
    std::ifstream fin;
    std::string str;
    std::forward_list<std::string> vstr;
    int list_size = 0;
    // int str_size = 0;
    // size_t rich = 0;
    bool r = 0;
    bool s = 0;
    int vel = 0;

    fin.open(argv[1]);
    if (!fin.is_open()) {
    
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
            vstr.push_front(str);
            list_size++;
        }
    }
    vstr.reverse();
    // size = std::count(vstr.begin(), vstr.end(), );
    std::cout << list_size << std::endl;
    for (auto n : vstr) {
        std::cout << n << std::endl;
    }
    // if (list_size == vel) {
        std::cout << vel << std::endl;
    // }
    if (r == 1) {

    }
    std::cout << r << std::endl;
    argc--;

    return 0;
}
