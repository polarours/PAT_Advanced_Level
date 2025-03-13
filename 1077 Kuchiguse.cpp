#include <bits/stdc++.h>

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, split))
        result.push_back(token);
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    std::vector<std::string> vec_str(N);
    for(int i = 0; i < N; i++) {
        std::getline(std::cin, vec_str[i]);
    }

   std::string res = vec_str[0];

    for(int i = 1; i < N; i++) {
        std::string cur_str = vec_str[i];
        int pos1 = res.length() - 1, pos2 = cur_str.size() - 1;
        int common_length = 0;
        while(pos1 >= 0 && pos2 >= 0 && res[pos1] == cur_str[pos2]) {
            common_length++;
            pos1--;
            pos2--;
        }
        res = res.substr(res.size() - common_length);
    }

    if(res.empty()) std::cout << "nai" << std::endl;
    else std::cout << res << std::endl;
    
    return 0;
}