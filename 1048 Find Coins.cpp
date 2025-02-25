#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;
    bool flag = false;
    std::vector<int> v(N);
    std::map<int, int> map_coins;
    for (int i = 0; i < N; i++) {
        int coin_number;
        std::cin >> coin_number;
        v[i] = coin_number;
    }

    //std::sort(v.begin(), v.end());
    int result1 = INT_MAX, result2 = INT_MIN, v1 = 0, v2 = 0;
    for(int i = 0; i < N; i++) {
        if(map_coins.find(M - v[i]) != map_coins.end()) {
            v1 = std::min(v[i], M - v[i]);
            v2 = std::max(v[i], M - v[i]);
            result1 = std::min(v1, result1);
            result2 = std::max(v2, result2);
            flag = true;
        }else {
            map_coins.insert(std::pair<int, int>(v[i], i));
        }
    }

    if(flag)
        std::cout << result1 << " " << result2 << std::endl;
    else
        std::cout << "No Solution" << std::endl;

    return 0;
}