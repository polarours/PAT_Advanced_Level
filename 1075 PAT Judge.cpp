#include <bits/stdc++.h>

int main() {
    int N, K, M;
    std::cin >> N >> K >> M;
    std::vector<int> vec_full_mark(K);
    for (int i = 0; i < K; i++) {
        std::cin >> vec_full_mark[i];
    }

    std::unordered_map<int, std::vector<int>> vec_stu_mark(N);
    for (int i = 1; i <= N; i++) {
        std::vector<int> v(K, -2);
        vec_stu_mark[i] = v;
    }

    int id, problem_id, mark;
    std::vector<int> vec;
    for(int i = 0; i < M; i++) {
        std::cin >> id >> problem_id >> mark;
        problem_id -= 1;
        std::vector<int> v = vec_stu_mark[id];
        v[problem_id] = mark > v[problem_id] ? mark : v[problem_id];
        vec_stu_mark[id] = v;
    }

    std::vector<std::tuple<int, int, int, int, std::vector<int>>> vec_order;//id solved_problems sum perfect v
    for(const auto& pair : vec_stu_mark) {
        int id = pair.first;
        std::vector<int> v = pair.second;
        int sum = 0, perfect_solved_problems = 0, solved_problems = 0;
        int index = 0;
        for(const auto num : v) {
            if(num != -1 && num != 0 && num != -2 && num == vec_full_mark[index]) perfect_solved_problems++;
            if(num != -1 && num != -2) {
                sum += num;
                solved_problems++;
            }
            index++;
        }
        if(solved_problems != 0)
            vec_order.push_back({id, solved_problems, sum, perfect_solved_problems, v});
    }

    std::sort(vec_order.begin(), vec_order.end(),[](std::tuple<int, int, int, int, std::vector<int>> a, std::tuple<int, int, int, int, std::vector<int>> b) {
        int perfect_solved_problems_a = std::get<3>(a), perfect_solved_problems_b = std::get<3>(b);
        int sum_a = std::get<2>(a), sum_b = std::get<2>(b);
        int id_a = std::get<0>(a), id_b = std::get<0>(b);
        if(sum_a == sum_b) {
            if(perfect_solved_problems_a == perfect_solved_problems_b)
                return id_a < id_b;
            return perfect_solved_problems_a > perfect_solved_problems_b;
        }
        return sum_a > sum_b;
    });

    int rank = 1;
    for(int i = 0; i < vec_order.size(); i++) {
        std::tuple<int, int, int, int, std::vector<int>> order = vec_order[i];
        auto [id, solved_pro, sum, perfect_solved, vec_pro] = order;
        if(i > 0 && sum < std::get<2>(vec_order[i - 1])) {
            rank = i + 1;
        }
        std::cout << rank << " " << std::setw(5) << std::setfill('0') << id << " " << sum << " ";
        int pro_size = 1;
        for(const auto& v : vec_pro) {
            if(pro_size != K) {
                if(v == -1) std::cout << 0 << " ";
                else if(v == -2) std::cout << "-" << " ";
                else std::cout << v << " ";
            }else {
                if(v == -1) std::cout << 0 << std::endl;
                else if(v == -2) std::cout << "-" << std::endl;
                else std::cout << v << std::endl;
            }
            pro_size++;
        }
    }

    return 0;
}