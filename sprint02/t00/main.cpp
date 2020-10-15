#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[]) {
    std::ifstream fin;
    std::string tmp;
    std::vector<std::string> vstr;
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
            vstr.push_back(tmp);
        }
        fin.close();
        // for_each();
        for (auto n : vstr) {
            while (index != std::string::npos) {
                index = n.find_first_of(' ');
                if (index != std::string::npos) {
                    tmp = n.substr(0, index);
                    std::cout << tmp << std::endl;
                    n.erase(0, tmp.size());
                } else {
                    
                }
                // index++;
                // tmp.erase(std::remove_if(tmp.begin(), tmp.end(),[](unsigned char x) {
                //     return std::isspace(x);
                // }), tmp.end());
                // std::cout << tmp << std::endl;
                // index = -1;
            }
            index = 0;
            // std::cout << n << std::endl;
        }
        // vstr.sort();
        // vstr.unique();
        // vstr.remove_if([](std::string fls) {
        //     return (fls.find('c') != std::string::npos
        //             || fls.find('b') != std::string::npos
        //             || fls.find('l') != std::string::npos) == true ? true : false;
        // });
        // std::for_each(vstr.begin(), vstr.end(), [](std::string &fls) {
        //     if (fls.size() > 10) {
        //         fls = "Long one";
        //     } else if (fls.size() < 4) {
        //         fls = "Short one";
        //     }
        // });
        // vstr.sort();
        // vstr.reverse();
        // for (auto n : vstr) {
        //     ofs << n << std::endl;
        // }
        ofs.close();
    }

    return 0;
}