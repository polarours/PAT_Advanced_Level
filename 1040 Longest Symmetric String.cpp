#include <bits/stdc++.h>

bool is_symmetric(std::string& s, int start, int end) {
    std::string str = s.substr(start, end - start + 1);
    int left = 0, right = str.size() - 1;
    while (left <= right) {
        if (str[left++] != str[right--]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    int result = 0;

    for (int i = 0; i < str.length(); i++) {
        for(int j = i; j < str.length(); j++) {
            bool flag = is_symmetric(str, i, j);
            if (flag) {
                result = std::max(result, j - i + 1);
            }
        }
    }


    std::cout << result << std::endl;

    return 0;
}