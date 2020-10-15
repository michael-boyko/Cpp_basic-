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
    
    if (argc != 2) {
        std::cout << "usage: ./stdAlgoV2 [file_name]" << std::endl;
        exit(0);
    }
    str = argv[1];
    fin.open(str);
    if (!fin.is_open()) {
        std::cout << "error" << std::endl;
    } else {
        std::ofstream ofs(str.insert(str.rfind('.'), "_mod"));
        while (getline(fin, str, '\n')) {
            vstr.push_front(str);
        }
        fin.close();
        vstr.sort();
        vstr.unique();
        vstr.remove_if([](std::string fls) {
            return (fls.find('c') != std::string::npos
                    || fls.find('b') != std::string::npos
                    || fls.find('l') != std::string::npos) == true ? true : false;
        });
        std::for_each(vstr.begin(), vstr.end(), [](std::string &fls) {
            if (fls.size() > 10) {
                fls = "Long one";
            } else if (fls.size() < 4) {
                fls = "Short one";
            }
        });
        vstr.sort();
        vstr.reverse();
        for (auto n : vstr) {
            ofs << n << std::endl;
        }
        ofs.close();
    }

    return 0;
}
