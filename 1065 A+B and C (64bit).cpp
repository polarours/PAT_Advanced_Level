#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<bool> v;

    long double a, b, c;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> b >> c;
        v.push_back(a + b > c);
    }

    for(int i = 0; i < v.size(); i++) {
        std::cout << "Case #" << i + 1 << ": ";
        if(v[i]) std::cout << "true";
        else std::cout << "false";
        std::cout << std::endl;
    }


    return 0;
}