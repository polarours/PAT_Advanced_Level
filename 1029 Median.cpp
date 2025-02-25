#include <bits/stdc++.h>

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, split)) {
        result.push_back(token);
    }
}

int main() {
    long int N_1, N_2, index = 0;
    std::vector<std::string> v_1, v_2;
    std::string str;
    std::getline(std::cin, str);

    StringSplit(str, ' ', v_1);
    std::getline(std::cin, str);
    StringSplit(str, ' ', v_2);

    N_1 = v_1.size() - 1;
    N_2 = v_2.size() - 1;
    std::vector<long int> vec;
    for(int i = 1; i <= N_1; i++) {
        vec.push_back(stol(v_1[i]));
    }
    for(int i = 1; i <= N_2; i++) {
        vec.push_back(stol(v_2[i]));
    }

    std::sort(vec.begin(), vec.end());

    long int result = 0;
    if(vec.size() % 2 == 1) {
        result = vec[(vec.size() - 1) / 2];
    }else {
        result = vec[(vec.size() / 2) - 1];
    }

    std::cout << result << std::endl;
    return 0;
}