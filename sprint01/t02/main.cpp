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

void check(std::deque<t_town *> d_towns, char *argv[]) {

}

int main(int argc, char *argv[]) {
    std::deque<t_town *> d_towns;
    const int t = 5;
    std::array<std::string, t> arr;

    for (int i = 0; i < argc - 1; i++) {
        arr[i] = argv[i];
    }
    // t_town *towns = NULL;
    // std::vector<std::string> v_str;
    // std::string str;
    // std::string tmp;
    // t_town town;
    // int from = 0;
    // int to = 0;

    if (argc == 1) {
        std::cout << "usage: ./visitAll [[name,stamina,distance] ...]" << std::endl;
    } else {
        // for (int i = 0; i < argc - 1; ++i) {
        //     towns = new t_town;
        //     str = argv[i + 1];
        //     to = str.find(",");
        //     // std::cout << to << "- to" << std::endl;
        //     tmp = str.substr(0, to);
        //     towns->name = tmp;
        //     from = to + 1;
        //     to = str.find(",", from);
        //     tmp = str.substr(from, to);
        //     towns->stamina = stoi(tmp);
        //     from = to + 1;
        //     tmp = str.substr(from);
        //     towns->distance = stoi(tmp);
        //     towns->id = i;
        //     d_towns.push_back(towns);
        //     str.clear();
        // }
        // for (int i = 0; i < d_towns.size(); ++i)
        // {
        // // int i = 1;
        //     std::cout << "name " + d_towns[i]->name + " | stamina " << d_towns[i]->stamina << " | distance " << d_towns[i]->distance << std:: endl;
        // }
    }
    // town.name = 

    // d_towns.push_back();
    return 0;
}