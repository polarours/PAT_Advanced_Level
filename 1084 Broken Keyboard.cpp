#include <bits/stdc++.h>

int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    std::vector<char> result;
    for(const auto& c1 : s1) {
        char ch1 = std::toupper(c1);
        bool found = false;
        for(const auto& c2 : s2) {
            char ch2 = std::toupper(c2);
            if(ch1 == ch2) {
                found = true;
                break;
            }
        }
        if(!found && std::find(result.begin(), result.end(), ch1) == result.end()) {
            result.push_back(ch1);
        }
    }

    for(const auto& c : result) {
        std::cout << c;
    }

    return 0;
}