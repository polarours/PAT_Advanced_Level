#include <bits/stdc++.h>

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, split))
        result.push_back(token);
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<std::string> vec1, vec2;
    std::vector<int> res(3);
    StringSplit(s1, '.', vec1);
    StringSplit(s2, '.', vec2);

    int carry = 0;
    res[2] = (std::stoi(vec1[2]) + std::stoi(vec2[2])) % 29;
    carry = (std::stoi(vec1[2]) + std::stoi(vec2[2])) / 29;
    res[1] = ((std::stoi(vec1[1]) + std::stoi(vec2[1])) + carry) % 17;
    carry = (std::stoi(vec1[1]) + std::stoi(vec2[1]) + carry) / 17;
    res[0] = std::stoi(vec1[0]) + std::stoi(vec2[0]) + carry;

    for(int i = 0; i < 3; i++) {
        if(i != 2)
            std::cout << res[i] << ".";
        else
            std::cout << res[i] << std::endl;
    }

    return 0;
}