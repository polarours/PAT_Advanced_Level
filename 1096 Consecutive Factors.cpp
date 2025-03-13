#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int maxLen = 0;
    int start = 0;
    for(int i  = 2; i <= std::sqrt(N); i++) {
        int len = 0, cur = 1;
        for(int j = i; ; j++) {
            cur *= j;
            len++;
            if(N % cur != 0) break;
            else if(N % cur == 0 && len > maxLen) {
                maxLen = len;
                start = i;
            }
        }
    }

    if(maxLen == 0) {
        maxLen = 1;
        start = N;
    }
    
    std::cout << maxLen << std::endl;
    for(int i = 0; i < maxLen; i++) {
        if(i != maxLen - 1)
            std::cout << start + i << "*";
        else
            std::cout << start + i << std::endl;
    }

    return 0;
}