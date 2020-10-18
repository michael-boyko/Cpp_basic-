#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>

void add_book(std::string &name, std::map<std::string, std::vector<std::string>> &books) {
    std::ifstream fin;
    std::vector<std::string> text;
    std::string str;

    if (books.find(name) == books.end()) {
        fin.open("./library/" + name);
        if (!fin.is_open()) {
            std::cout << "invalid book" << std::endl;
        } else {
            while (getline(fin, str)) {
                text.push_back(str);
            }
            books.emplace(name, text);
            std::cout << name << " added" << std::endl;
        }
    } else {
        std::cout << name << " added" << std::endl;
    }
}

void delete_book(std::string &name, std::map<std::string, std::vector<std::string>> &books) {
    auto book = books.find(name);

    if (book != books.end()) {
        books.erase(book);
        std::cout << name << " deleted" << std::endl;
    } else {
        std::cout << "invalid book" << std::endl;
    }
}

void read_book(std::string &name, std::map<std::string, std::vector<std::string>> &books) {
    auto book = books.find(name);

    if (book != books.end()) {
        for (auto n : book->second) {
        	std::cout << n << std::endl;
        }
    } else {
        std::cout << "invalid book" << std::endl;
    }
}

void list_of_books(std::map<std::string, std::vector<std::string>> &books) {
    for (auto n : books) {
        std::cout << n.first << std::endl;
    }
}

void commands_handler(std::vector<std::string> &parsered_commands,
                      std::map<std::string, std::vector<std::string>> &books) {
    auto amount_commans = parsered_commands.size();

    if (parsered_commands[0] == "add" && amount_commans == 2) {
        add_book(parsered_commands[1], books);
    } else if (parsered_commands[0] == "delete" && amount_commans == 2) {
        delete_book(parsered_commands[1], books);
    } else if (parsered_commands[0] == "read" && amount_commans == 2) {
        read_book(parsered_commands[1], books);
    } else if (parsered_commands[0] == "list") {
        list_of_books(books);
    } else if (parsered_commands[0] == "quit") {
        std::cout << "bey" << std::endl;
        exit(1);
    } else {
        std::cout << "invalid command" << std::endl;
    }
}

std::vector<std::string> input_handler(std::string &command) {
    std::vector<std::string> parsered_commands;
    std::string tmp;
    std::stringstream stream(command);

    while (getline(stream, tmp, ' ')) {
        if (tmp.size() != 0) {
            parsered_commands.push_back(tmp);
        }
    }

    return parsered_commands;
}

int main() {
    std::string command;
    std::vector<std::string> parsered_commands;
    std::map<std::string, std::vector<std::string>> books;

    while (1) {
        std::cout << "enter command:> ";
        getline(std::cin, command);
        if (!command.empty()) {
            parsered_commands = input_handler(command);
            if (parsered_commands.size() > 2) {
                std::cout << "invalid command" << std::endl;
            } else {
                commands_handler(parsered_commands, books);
                parsered_commands.clear();
            }
        }
    }
    return 0;
}
