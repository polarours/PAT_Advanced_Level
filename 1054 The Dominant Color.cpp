#include <bits/stdc++.h>


int main() {
    int M, N;
    std::cin >> M >> N;
    int number, count = 0, color;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> color;
            if(count == 0) {
                number = color;
                count++;
            }else {
                if(color == number) count++;
                else count--;
            }
        }
    }

    std::cout << number << std::endl;

    return 0;
}