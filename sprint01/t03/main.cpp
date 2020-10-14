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

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

int male = 0;
int female = 0;
int m_vampirev = 0;
int f_vampirev = 0;

void init_rabbits(std::list<struct Rabbit *> &rabbits) {
    struct Rabbit *r = NULL;
    int chance = 0;

    for (int i = 0; i < 10; i++) {
        r = new struct Rabbit;
        chance = std::rand() % 100;
        if (chance >= 50) {
            if (chance == 72) {
                m_vampirev++;
                r->isVampire = 1;
                r->age = 8;
            }
            else {
                r->isVampire = 0;
                r->age = 3;
            }
            male++;
            r->gender = Gender::Male;
        } else {
            if (chance == 31) {
                f_vampirev++;
                r->isVampire = 1;
                r->age = 8;
            }
            else {
                r->isVampire = 0;
                r->age = 3;
            }
            female++;
            r->gender = Gender::Female;
        }
        rabbits.push_back(r);
    }
}

int amount_new_rabbits(void) {
    int amount = 0;

    if (male - m_vampirev == female - f_vampirev) {
        amount = male - m_vampirev;
    } else if (male - m_vampirev > female - f_vampirev) {
        amount = female - f_vampirev;
    } else {
        amount = male - m_vampirev;
    }

    return amount < 0 ? 0 : amount;
}

void delete_rabbits(std::list<struct Rabbit *> &rabbits) {
    // auto i = rabbits.begin();
    int e = 0;

    for (auto r : rabbits) {
        // std::cout << e << std::endl;
        // std::cout << r->age << std::endl;
        if (r->age == 0) {
            std::cout << r->isVampire << std::endl;
            if (r->isVampire == 0) {
                if (static_cast<int>(r->gender) == 0) {
                    male--;
                } else {
                    female--;
                }
            } else {
                if (static_cast<int>(r->gender) == 0) {
                    m_vampirev--;
                    male--;
                } else {
                    f_vampirev--;
                    female--;
                }
            }
            // i = rabbits.erase(i);
        } else {
            (r->age)--;
        }
        e++;
    }
}

void create_rabbits(std::list<struct Rabbit *> &rabbits) {
    struct Rabbit *r = NULL;
    int chance = 0;
    int amount = amount_new_rabbits();

    for (int i = 0; i < amount; i++) { //initialization 10 rabbits
        r = new struct Rabbit;
        chance = std::rand() % 100;
        if (chance >= 50) {
            if (chance == 72) {
                m_vampirev++;
                r->isVampire = 1;
                r->age = 8;
            }
            else {
                r->isVampire = 0;
                r->age = 3;
            }
            male++;
            r->gender = Gender::Male;
        } else {
            if (chance == 31) {
                f_vampirev++;
                r->isVampire = 1;
                r->age = 8;
            }
            else {
                r->isVampire = 0;
                r->age = 3;
            }
            female++;
            r->gender = Gender::Female;
        }
        rabbits.push_back(r);
    }
}

int main() {
    std::list<struct Rabbit *> rabbits;
    int e = 0;

    std::srand(std::time(0));
    init_rabbits(rabbits);
    // std::cout << "Males: " << male << std::endl;
    // std::cout << "Females: " << female << std::endl;
    // std::cout << "Vampire: " << m_vampirev + f_vampirev << std::endl;
    while (male + female > 0 && male + female < 1000) {
        sleep(1);
        std::cout << std::endl;
        std::cout << "Males: " << male << std::endl;
        std::cout << "Females: " << female << std::endl;
        std::cout << "Vampire: " << m_vampirev + f_vampirev << std::endl;
        // std::cout << e << std::endl;
        
        create_rabbits(rabbits);
        delete_rabbits(rabbits);
        e++;
           
    }
    
    // for (const auto n : rabbits) {
    //     if (static_cast<int>(n->gender) == 0) {
    //         std::cout << "Male" << std::endl;
    //         std::cout << "Vampire " << n->isVampire << std::endl;
    //         std::cout << "age " << n->age << std::endl;
    //     } else {
    //         std::cout << "Female" << std::endl;
    //         std::cout << "Vampire " << n->isVampire << std::endl;
    //         std::cout << "age " << n->age << std::endl;
    //     }
    //     std::cout << std::endl;
    // }



    return 0;
}
