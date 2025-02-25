#include<bits/stdc++.h>

int main() {
    std::string s1, s2, res;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    for(const auto& c : s1) {
        if(s2.find(c) == std::string::npos) {
            res += c;
        }
    }

    std::cout << res << std::endl;

    return 0;
}