#include <bits/stdc++.h>

std::string multiply(const std::string& str,int k) {
    std::string result;
    int carry = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        int digit = (str[i] - '0') * k + carry;
        result.push_back(digit % 10 + '0');
        carry = digit / 10;
    }
    if (carry) {
        result.push_back(carry + '0');
    }
    std::reverse(result.begin(),result.end());
    return result;
}

bool isPermutation(const std::string & s1, const std::string & s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    std::string sortedS1 = s1;
    std::string sortedS2 = s2;
    // 对两个字符串进行排序
    std::sort(sortedS1.begin(), sortedS1.end());
    std::sort(sortedS2.begin(), sortedS2.end());
    // 比较排序后的字符串是否相等
    return sortedS1 == sortedS2;
}

int main() {
    std::string num;
    std::cin >> num;

    std::string double_num = multiply(num,2);
    bool flag = isPermutation(num, double_num);
    if(flag) {
        std::cout << "Yes" << std::endl;
    }else {
        std::cout << "No" << std::endl;
    }
    std::cout << double_num << std::endl;

    return 0;
}
