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
    std::multiset<std::string> str;
    std::multiset<std::string> str_clear;
    unsigned long int index = 0;
    int count = 0;
    
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
                str_clear.insert(tmp);
            }
            if (n.find_first_not_of(" ") != std::string::npos) {
                n.erase (std::remove_if (n.begin (), n.end (), ispunct), n.end ());
                str_clear.insert(n);
            }
            index = 0;
        }
        auto p_equal = str_clear.equal_range(*str_clear.begin());
        while (index < str_clear.size()) {
            tmp = *p_equal.first;
            if (p_equal.first == p_equal.second) {
                count++;
            }
            while (p_equal.first != p_equal.second) {
                p_equal.first++;
                count++;
            }
            p_equal = str_clear.equal_range(*p_equal.second);
            ofs << tmp << ": " << count << std::endl;
            index += count;
            count = 0;
        }
        ofs.close();
    }

    return 0;
}
