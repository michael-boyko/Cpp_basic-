#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <array>
#include <list>
#include <cstdlib>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

int main() {
    std::list<struct Rabbit *> rabbit;
    struct Rabbit *r = NULL;
    int chance = 0;

    std::srand(std::time(0));

    // std::cout << rand()%100 << std::endl;

    for (int i = 0; i < 10; i++) {
        r = new struct Rabbit;
        Gender g = Gender::Male;
        chance = rand() % 100;
        if (chance >= 50) {
            r->gender = g;
            r->isVampire = 0;
            r->age = 3;
        } else {
            r->gender = Female;
            r->isVampire = 0;
            r->age = 3;
        }
        rabbit.push_back(r);
    }

    for (const auto n : rabbit) {
        std::cout << n->gender << std::endl;
    }



    return 0;
}
