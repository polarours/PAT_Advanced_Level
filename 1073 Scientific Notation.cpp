#include <bits/stdc++.h>

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, split))
        result.push_back(token);
}

int main() {
    std::string str;
    std::cin >> str;

    bool flag = true;
    if(str[0] == '-') flag = false;
    int index_point = 0, index_exp_flag, index_E;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '.') index_point = i;
        if(str[i] == 'E') index_E = i;
    }
    index_exp_flag = index_E + 1;
    bool flag_exp = true;
    if(str[index_exp_flag] == '-') flag_exp = false;
    std::string str_exp = "";
    for(int i = index_exp_flag + 1; i < str.size(); i++) {
        str_exp += str[i];
    }
    int exp = std::stoi(str_exp);
    int len = index_E - index_point - 1;
    std::string res = "";
    if(flag_exp) {//右移
        for(int i = 1; i < index_point; i++) {
            res += str[i];
        }
        if(exp < len) {
            for(int i = 0; i < exp; i++) {
                res += str[index_point + 1 + i];
            }
            res += ".";
            for(int i = 0; i < len - exp; i++) {
                res += str[index_point + exp + 1 + i];
            }
        }else {
            int diff = exp - len;
            for(int start = index_point + 1, i = 0; i < index_E - index_point - 1; i++) {
                res += str[start + i];
            }
            for(int i = 0; i < diff; i++) {
                res += "0";
            }
        }
    }else {//左移
        for(int i = 1; i < index_point; i++) {
            res += str[i];
        }
        int left_size = index_point - 1;
        std::string str_exp = "";
        for(int i = index_exp_flag + 1; i < str.size(); i++) {
            str_exp += str[i];
        }
        int exp = std::stoi(str_exp);
        if(exp < left_size) {
            for(int start = 1, i = 0; i < left_size - exp; i++) {
                res += str[start + i];
            }
            res += ".";
            for(int i = left_size - exp + 2; i < str.size(); i++) {
                if(str[i] == 'E') break;
                res += str[i];
            }
        }else {
            res = "0.";
            int size = exp - left_size;
            for(int i = 0; i < size; i++) {
                res += "0";
            }
            for(int i = 1; i < str.size(); i++) {
                if(str[i] == '.') continue;
                if(str[i] == 'E') break;
                res += str[i];
            }
        }
    }

    if(!flag) res = "-" + res;

    std::cout << res << std::endl;

    return 0;
}