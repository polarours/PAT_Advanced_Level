#include <bits/stdc++.h>

int main() {
    std::string str;
    std::cin >> str;
    int N = str.length();
    int n1 =(N + 2) / 3, n3 = n1;
    int n2 = N + 2 - 2 * n1;
    int left = 0, right = str.length() - 1;
    while(left < n1 - 1) {
        std::cout << str[left++];
        for(int j = 0; j < n2 - 2; j++) {
            std::cout << " ";
        }
        std::cout << str[right--] << std::endl;
    }

    for(int i = left; i <= right; i++) {
        std::cout << str[i];
    }

    return 0;
}