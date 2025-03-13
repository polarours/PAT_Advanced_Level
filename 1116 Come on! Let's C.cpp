#include <bits/stdc++.h>

bool is_prime(int num) {
    if(num == 1) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;

    std::string stu_id;
    std::unordered_map<std::string, int> stu;

    for(int i = 0; i < N; i++) {
        std::cin >> stu_id;
        stu[stu_id] = i + 1;
    }


    std::vector<std::string> res;
    std::map<std::string, bool> visited;
    int K;
    std::cin >> K;
    std::string query_id;
    while(K--) {
        std::cin >> query_id;
        if(stu.find(query_id) == stu.end()) {
            res.push_back(query_id + ": " + "Are you kidding?");
        }else {
            int rank = stu[query_id];
            if(visited.find(query_id) == visited.end()) {
                visited[query_id] = true;
                if(rank == 1) res.push_back(query_id + ": " + "Mystery Award");
                else if(is_prime(rank)) res.push_back(query_id + ": " + "Minion");
                else res.push_back(query_id + ": " + "Chocolate");
            }
            else res.push_back(query_id + ": " + "Checked");
        }
    }

    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}