#include <bits/stdc++.h>

bool is_real(std::string str) {
    bool flag = true;
    int point_cnt = 0, decimal_index = 0;
    bool decimal_exist = false;
    if(str[0] == '-') str = str.substr(1);
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '.') {
            decimal_exist = true;
            decimal_index = i;
            if(point_cnt == 0)
                point_cnt++;
            else {
                flag = false;
                break;
            }
        }else if(str[i] < '0' || str[i] > '9') {
            flag = false;
            break;
        }
    }
    if(!flag) return false;
    if(decimal_exist) {
        if(str.size() - 1 - decimal_index <= 2 && std::stod(str) <= 1000) return true;
        return false;
    }
    return std::abs(std::stod(str)) <= 1000;
}

int main() {
    int N;
    std::cin >> N;

    int real_num = 0;
    std::string s;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        if(is_real(s)) {
            real_num++;
            double d = std::stod(s);
            sum += d;
        }else {
            std::cout << "ERROR: " << s << " is not a legal number" << std::endl;
        }
    }

    if(real_num == 0) std::cout << "The average of 0 numbers is Undefined" << std::endl;
    else if(real_num == 1) std::cout << "The average of 1 number is " << std::fixed << std::setprecision(2) << sum << std::endl;
    else std::cout << "The average of " << real_num << " numbers is " << std::fixed << std::setprecision(2) << sum / real_num << std::endl;

    return 0;
}