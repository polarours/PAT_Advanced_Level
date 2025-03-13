#include <bits/stdc++.h>

const std::string arr_1[] = {"", " Shi", " Bai", " Qian", " Wan", " Shi", " Bai", " Qian", " Yi"};
const std::string arr_2[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    std::string str;
    std::cin >> str;

    if(str == "0") {
        std::cout << "ling" << std::endl;
        return 0;
    }

    if(str[0] == '-') {
        std::cout << "Fu ";
        str = str.substr(1);
    }

    int len = str.length(), gap = 0;
    for(int i = 1; i <= len; i++) {//123456 100123
        int n = str[i - 1] - '0';
        if(n != 0) {
            if(gap) {
                std::cout << " ling";
                gap = 0;
            }
            if(i > 1) std::cout << " ";
            std::cout << arr_2[n] << arr_1[len - i];
        }else {
            gap++;
            if((len - i) % 4 == 0 && gap % 4 != 0) {
                std::cout << arr_1[len - i];
                gap = 0;
            }
        }
    }

    return 0;
}