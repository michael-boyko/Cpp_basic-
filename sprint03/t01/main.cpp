#include "outputAny.h"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <array>

int main() {
    std::string str = "aaasdfds";
    std::vector<std::string> vector = {"VVVaasdfds", "aaasdfds", "VVVaasdfds"};
    std::deque<std::string> deque = {"DDDaasdfds", "aaasdfds", "DDDaasdfds"};
    std::list<std::string> list = {"LLLaasdfds", "aaasdfds", "LLLaasdfds"};
    std::forward_list<std::string> forwardList = {"FFFaasdfds", "aaasdfds", "FFFaasdfds"};
    std::set<std::string> set = {"SSSaasdfds", "aaasdfds", "SSSaasdfds"};
    std::array<std::string, 3> array = {"AAAaasdfds", "aaasdfds", "AAAaasdfds"};

    outputAny(str);
    outputAny(vector);
    outputAny(deque);
    outputAny(list);
    outputAny(forwardList);
    outputAny(set);
    outputAny(array);

    return 0;
}