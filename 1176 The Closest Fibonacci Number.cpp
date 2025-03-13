#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int f[1000000];
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i < 1000000; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    int cur_dis, min_dis = INT_MAX;
    int res = 0;
    for(int i = 0; i < 1000000; i++) {
        cur_dis = std::abs(f[i] - N);
        if(cur_dis < min_dis) {
            min_dis = cur_dis;
            res = f[i];
        }else {
            break;
        }
    }

    std::cout << res << std::endl;

    return 0;
}