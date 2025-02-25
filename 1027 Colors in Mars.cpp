#include <bits/stdc++.h>

std::string convert_radix(int num) {
    std::string result;
    if(num == 0)
        return "00";
    while (num > 0) {
        if(num % 13 < 10) {
            result += num % 13 + '0';
        }else {
            result += num % 13 - 10 + 'A';
        }
        num /= 13;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int N_1, N_2, N_3;
    std::cin >> N_1 >> N_2 >> N_3;

    std::string s_1, s_2, s_3;
    s_1 = convert_radix(N_1);
    s_2 = convert_radix(N_2);
    s_3 = convert_radix(N_3);

    std::cout << "#" << std::setw(2) << std::setfill('0') << s_1 << std::setw(2) << std::setfill('0') << s_2 << std::setw(2) << std::setfill('0') << s_3 << std::endl;

    return 0;
}