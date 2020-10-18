#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <map>


void print_all(std::multimap<std::string, std::string> &books) {
    int amount = 0;
    int count = 1;
    std::string tmp = "";

    for (auto n : books) {
        amount = books.count(n.first);
        if (tmp != n.first) {
            count = 1;
            std::cout << n.first << ":" << std::endl;
            std::cout << " " << count << ": " << n.second << std::endl;
        } else {
            count++;
            std::cout << " " << count << ": " << n.second << std::endl;
        }
        tmp = n.first;
    }
}

int main(int argc, char *argv[]) {
    int num_str = 1;
    std::ifstream fin;
    std::string tmp;
    std::multimap<std::string, std::string> books;
    std::regex regular("(\\s*\")"
                       "(\\w+\\s?\\w+)"
                       "(\"\\s*:\\s*\")"
                       "(.+)"
                       "(\"\\s*)");
    std::cmatch result;

    if (argc != 2) {
        std::cout << "usage: ./tesLibrary [file_name]" << std::endl;
        exit(0);
    }
    tmp = argv[1];
    fin.open(tmp);
    if (!fin.is_open()) {
        std::cout << "error" << std::endl;
    } else {
        while (getline(fin, tmp, '\n')) {
            if (!tmp.empty()) {
                if (!std::regex_match(tmp.c_str(), result, regular)) {
                    std::cout << "Line " << num_str << " is invalid" << std::endl;
                    exit(0);
                }
                num_str++;
                books.emplace(result[2], result[4]);
            }
        }
        print_all(books);
        fin.close();
    }

    return 0;
}
