#include <bits/stdc++.h>

int main() {
    int K, N;
    std::cin >> K;

    std::vector<std::string> res;
    while(K--) {
        std::cin >> N;
        std::vector<int> v(N);
        for (int i = 0; i < N; i++) {
            std::cin >> v[i];
        }

        bool is_valid = true;
        std::unordered_map<int, int> map_row;
        for (int i = 0; i < N; i++) {
            if(map_row.find(v[i] - 1) == map_row.end()) {
                map_row[v[i] - 1] = 1;
            }else {
                is_valid = false;
                break;
            }
        }
        if(is_valid) {
            bool is_valid_diag = true;
            std::unordered_map<int, int> map_diag;
            for (int i = 0; i < N; i++) {
                if(map_diag.find(std::abs(v[i] + 1 + i)) == map_diag.end()) {
                    map_diag[std::abs(v[i] + 1 + i)] = 1;
                }else {
                    is_valid_diag = false;
                    break;
                }
            }
            if(is_valid_diag) res.push_back("YES");
            else res.push_back("NO");
        }else {
            res.push_back("NO");
        }
    }

    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}