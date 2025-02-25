#include<bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    std::vector<int> prefix(N + 1, 0);
    for(int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + D[i];
    }

    std::vector<std::pair<int, int>> exact;
    std::vector<std::pair<int, int>> closest;
    int min_diff = INT_MAX;

    for(int i = 0; i < N; i++) {
        int target = prefix[i] + M;

        auto it = std::lower_bound(prefix.begin() + i + 1, prefix.end(), target);

        if(it == prefix.end()) continue;

        int k = it - prefix.begin();
        int j = k - 1;

        int sum = prefix[k] - prefix[i];

        if(sum == M) {
            exact.push_back(std::make_pair(i + 1, j + 1));
        }else {
            int diff = sum - M;
            if(diff < min_diff) {
                min_diff = diff;
                closest.clear();
                closest.emplace_back(i + 1, j + 1);
            }else if(diff == min_diff) {
                closest.emplace_back(i + 1, j + 1);
            }
        }
    }

    if(!exact.empty()) {
        for(const auto& p : exact) {
            std::cout << p.first << "-" << p.second << "\n";
        }
    }else {
        for(auto& p : closest) {
            std::cout << p.first << "-" << p.second << "\n";
        }
    }

    return 0;
}