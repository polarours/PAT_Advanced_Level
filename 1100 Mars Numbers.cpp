#include<bits/stdc++.h>

const std::string arr_1[13] = {"","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const std::string arr_2[13] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, split)) {
        result.push_back(token);
    }
}

std::string convert(std::string& str) {
    std::string res = "";
    if(str == "0") return "tret";
    if(str == "tret") return "0";
    if(str[0] >= '0' && str[0] <= '9') {//转火星语
        int num = std::stoi(str);
        if(num > 13 && num % 13 != 0) {
            res = " ";
            res += arr_1[num % 13];
            res = arr_2[num / 13] + res;
        }else if(num % 13 == 0 && num >= 13){
            res = arr_2[num / 13];
        }else {
            res = arr_1[num % 13];
        }
    }else {//转地球语
        if(str.size() > 3) {
            std::vector<std::string> temp;
            StringSplit(str, ' ', temp);
            int index_1 = 0, index_2 = 0;
            for(int i = 0; i < 13; i++) {
                if(arr_2[i] == temp[0]) {
                    index_1 = i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++) {
                if(arr_1[i] == temp[1]) {
                    index_2 = i;
                    break;
                }
            }
            res = std::to_string(13 * index_1 + index_2);
        }else {
            int index_1 = 0, index_2 = 0;
            for(int i = 0; i < 13; i++) {
                if(arr_1[i] == str) {
                    index_1 = i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++) {
                if(arr_2[i] == str) {
                    index_2 = i;
                    break;
                }
            }
            if(index_1 != 0) {
                res = std::to_string(index_1);
            }else {
                res = std::to_string(index_2 * 13);
            }
        }
    }
    return res;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    std::vector<std::string> result;
    std::string s;
    for(int i = 0; i < N; i++) {
        std::getline(std::cin, s);
        result.push_back(convert(s));
    }

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }


    return 0;
}