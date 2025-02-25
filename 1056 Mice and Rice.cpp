#include <bits/stdc++.h>

int main() {
    int N_p, N_g;
    std::cin >> N_p >> N_g;

    std::vector<int> vec_weight_mice(N_p);
    for (int i = 0; i < N_p; i++) {
        std::cin >> vec_weight_mice[i];
    }

    std::vector<int> vec_order(N_p);
    for (int i = 0; i < N_p; i++) {
        std::cin >> vec_order[i];
    }

    //存储每个程序员的排名
    std::vector<int> ranks(N_p, 0);

    //当前顺序
    std::vector<int> current_order = vec_order;

    while(current_order.size() > 1) {
        int group_count = (current_order.size() + N_g - 1) / N_g;
        std::vector<int> next_order;
        for (int i = 0; i < group_count; i++) {
            int start = i * N_g;
            int end = std::min(start + N_g, static_cast<int>(current_order.size()));

            int max_weight = INT_MIN;
            int winner = -1;

            for(int j = start; j < end; j++) {
                int mouse = current_order[j];
                if(vec_weight_mice[mouse] > max_weight) {
                    max_weight = vec_weight_mice[mouse];
                    winner = mouse;
                }
            }

            for(int j = start; j < end; j++) {
                if(current_order[j] != winner) {
                    ranks[current_order[j]] = group_count + 1;
                }
            }

            next_order.push_back(winner);
        }
        current_order = next_order;
    }

    ranks[current_order[0]] = 1;

    for(int i = 0; i < N_p; i++) {
        if(i != N_p - 1) {
            std::cout << ranks[i] << " ";
        } else {
            std::cout << ranks[i] << std::endl;
        }
    }

    return 0;
}