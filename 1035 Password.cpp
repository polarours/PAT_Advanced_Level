#include <wchar.h>
#include <bits/stdc++.h>

bool is_modified(std::string str) {
    for(const char c : str) {
        if(c == '1' || c == '0' || c == 'l' || c == 'O') {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<std::string, std::string>> vec;
    std::vector<std::pair<std::string, std::string>> result;

    for (int i = 0; i < N; i++) {
        std::string count, password;
        std::cin >> count >> password;
        vec.push_back(std::pair<std::string, std::string>(count, password));
    }

    int not_modified_number = N;
    for(const auto& pair : vec) {
        std::string count = pair.first, password = pair.second;
        bool flag = is_modified(password);
        if(flag) {
            not_modified_number--;
            std::replace(password.begin(), password.end(), '1', '@');
            std::replace(password.begin(), password.end(), '0', '%');
            std::replace(password.begin(), password.end(), 'l', 'L');
            std::replace(password.begin(), password.end(), 'O', 'o');
            result.push_back(std::pair<std::string, std::string>(count, password));
        }
    }

    if(not_modified_number == N) {
        if(not_modified_number == 1) {
            std::cout << "There is " << not_modified_number << " account and no account is modified" << std::endl;
        }else {
            std::cout << "There are " << not_modified_number << " accounts and no account is modified" << std::endl;
        }

    }else {
        std::cout << N - not_modified_number << std::endl;
        for(const auto& pair : result) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }


    return 0;
}