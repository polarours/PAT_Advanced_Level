#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int result = 0;
    std::unordered_map<int, int> map;
    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        if(map.find(num) == map.end()) {
            map[num] = 1;
        }else {
            map[num]++;
        }
    }

    for(const auto& it : map) {
        if(it.second == 1) {
            result = it.first;
        }
    }

    if(result == 0){
        std::cout << "None" << std::endl;
    }else{
        std::cout << result << std::endl;
    }

    return 0;
}