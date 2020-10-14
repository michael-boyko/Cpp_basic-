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
int born_vapire = 0;

void init_rabbits(std::list<struct Rabbit *> &rabbits) {
    struct Rabbit *r = NULL;
    int chance = 0;

    for (int i = 0; i < 10; i++) {
        r = new struct Rabbit;
        chance = std::rand() % 100;
        if (chance >= 50) {
            if (chance == 101) {
                born_vapire++;
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
            if (chance == 0) {
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
    auto i = rabbits.begin();
    int amount_vampire = m_vampirev + f_vampirev;

    for (auto r : rabbits) {
        if (r->age == 0) {
            // std::cout << r->isVampire << std::endl;
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
            i = rabbits.erase(i);
        } else {
            if (r->isVampire == 0 && amount_vampire > 0) {
                if (static_cast<int>(r->gender) == 0) {
                    m_vampirev++;
                    r->isVampire = 1;
                    r->age += 5;
                } else {
                    f_vampirev++;
                    r->isVampire = 1;
                    r->age += 5;
                }
                amount_vampire--;
            }
            (r->age)--;
            i++;
        }
    }
}

void create_rabbits(std::list<struct Rabbit *> &rabbits) {
    struct Rabbit *r = NULL;
    int chance = 0;
    int amount = amount_new_rabbits();

    for (int i = 0; i < amount; i++) {
        r = new struct Rabbit;
        chance = std::rand() % 100;
        if (chance >= 50) {
            if (chance == 101) {
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
            if (chance == 0) {
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

    std::srand(std::time(0));
    init_rabbits(rabbits);
    while (male + female > 0 && male + female < 1000) {
        std::cout << std::endl;
        std::cout << "Males: " << male << std::endl;
        std::cout << "Females: " << female << std::endl;
        std::cout << "Vampire: " << m_vampirev + f_vampirev << std::endl;
        
        create_rabbits(rabbits);
        delete_rabbits(rabbits);
        sleep(1);
    }

    return 0;
}
