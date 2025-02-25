#include <bits/stdc++.h>

int main() {
    int N, sum_dis = 0;
    std::cin >> N;
    std::vector<int> prefix(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        int dis;
        std::cin >> dis;
        sum_dis += dis;
        prefix[i] = sum_dis;
    }

    int M;
    std::cin >> M;

    std::vector<int> result;
    for(int i = 0; i < M; i++) {
        int num1, num2, sum = 0;
        std::cin >> num1 >> num2;
        int a = std::min(num1, num2), b = std::max(num1, num2);
        sum = prefix[b - 1] - prefix[a - 1];
        result.push_back(std::min(sum_dis - sum, sum));
    }
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << '\n';
    }
    return 0;
}