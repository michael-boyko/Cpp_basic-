#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <array>

typedef struct s_town {
    std::string name;
    int stamina;
    int distance;
    int id;
} t_town;

int count_words(const std::string &str) {
    int count = 0;

    for (long unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == ',') {
            count++;
        }
    }

    return count;
}

bool check_input(std::deque<t_town *> &towns, const std::vector<std::string> &arr) {
    int from = 0;
    int to = 0;
    int id = 0;
    std::string tmp;
    t_town *town = NULL;


    for (auto const &element : arr) {
        if (count_words(element) != 2) {
            std::cout << "Argument " << element << " is not valid" << std::endl;
            return false;
        } else {
            town = new t_town;
            to = element.find(",");
            tmp = element.substr(0, to);
            if (tmp.empty()) {
                std::cout << "Argument " << element << " is not valid" << std::endl;
                return false;
            }
            town->name = tmp;
            // element = element.substr(to + 1, element.size());
            // std::cout << from << " | ";
            from = to + 1;
            // std::cout << from << " | ";
            to = element.find(",", from);
            // std::cout << to << " | ";
            tmp = element.substr(from, to - from);
            // std::cout << tmp << " | ";  
            if (tmp.find_first_not_of("0123456789") != std::string::npos) {
                std::cout << "1Argument " << element << " is not valid" << std::endl;
                return false;
            }
            town->stamina = stoi(tmp);
            from = to + 1;
            tmp = element.substr(from);
            // std::cout << tmp << " | ";
            if (tmp.find_first_not_of("0123456789") != std::string::npos) {
                std::cout << "2Argument " << element << " is not valid" << std::endl;
                return false;
            }
            town->distance = stoi(tmp);
            town->id = id;
            towns.push_back(town);
            id++;
        }
    }

    return true;
}

void find_route(std::deque<t_town *> &towns) {
    t_town *tmp = NULL;
    int t = 0;
    int energy = -1;

    for (unsigned long int i = 0; i < towns.size(); i++) {
        if (towns[t]->stamina < towns[t]->distance) {
            tmp = towns.front();
            towns.pop_front();
            towns.push_back(tmp);
            tmp = NULL;
            t = 0;
        }
        else {
            energy = 0;
            for (unsigned long int j = 0; j < towns.size(); j++) {
                energy += towns[j]->stamina - towns[j]->distance;
                // std::cout << energy << std::endl;
                if (energy < 0) {
                    j = towns.size();
                    tmp = towns.front();
                    towns.pop_front();
                    towns.push_back(tmp);
                    tmp = NULL; 
                }

            }
        }
    }
    if (energy < 0) {
        std::cout << "Mission: Impossible" << std::endl;
    } else {
        for (const auto& n : towns) {
            std::cout << n->id << " " << n->name << std::endl;
        }        
    }
}

int main(int argc, char *argv[]) {
    std::deque<t_town *> towns;
    std::vector<std::string> arr;

    for (int i = 0; i < argc - 1; i++) {
        arr.push_back(argv[i + 1]);
    }
    if (argc == 1) {
        std::cout << "usage: ./visitAll [[name,stamina,distance] ...]" << std::endl;
    } else if (check_input(towns, arr) == true) {
        find_route(towns);
    }

    return 0;
}