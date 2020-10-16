#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>

int main(int argc, char *argv[]) {
    std::ifstream fin;
    std::string tmp;
    std::set<std::string> str;
    std::set<std::string> str_uniq;
    unsigned long int index = 0;
    
    if (argc != 2) {
        std::cout << "usage: ./uniqueWords [file_name]" << std::endl;
        exit(0);
    }
    tmp = argv[1];
    fin.open(tmp);
    if (!fin.is_open()) {
        std::cout << "error" << std::endl;
    } else {
        std::ofstream ofs(tmp.insert(tmp.rfind('.'), "_mod"));
        while (getline(fin, tmp, '\n')) {
            str.insert(tmp);
        }
        fin.close();
        for (auto n : str) {
            index = n.find_first_of(' ');
            while (index != std::string::npos) {
                tmp = n.substr(0, index);
                n.erase(0, tmp.size() + 1);
                index = n.find_first_of(' ');
                tmp.erase (std::remove_if (tmp.begin (), tmp.end (), ispunct), tmp.end ());
                str_uniq.insert(tmp);
            }
            if (n.find_first_not_of(" ") != std::string::npos) {
                n.erase (std::remove_if (n.begin (), n.end (), ispunct), n.end ());
                str_uniq.insert(n);
            }
            index = 0;
        }
        for (auto n : str_uniq) {
            ofs << n << std::endl;
        }
        ofs.close();
    }

    return 0;
}
