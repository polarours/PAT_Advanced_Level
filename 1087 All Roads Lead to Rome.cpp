#include <bits/stdc++.h>

void dfs_find_path(std::vector<std::vector<int>>& graph, int current, int target, std::vector<bool>& visited, std::vector<int>& path, std::vector<std::vector<int>>& all_paths) {
    visited[current] = true;
    path.push_back(current);
    if(current == target) {
        all_paths.push_back(path);
    }else {
        for(int i = 0; i < graph.size(); i++) {
            if(!visited[i] && graph[current][i] != 0) {
                dfs_find_path(graph, i, target, visited, path, all_paths);
            }
        }
    }
    visited[current] = false;
    path.pop_back();
}

int main() {
    int N, K;
    std::string start_city;
    std::cin >> N >> K >> start_city;
    std::map<std::string, int> city_index;
    city_index[start_city] = 0;
    std::map<std::string, int> city_happiness_count;
    std::string city_name;
    int city_happiness;
    for (int i = 1; i <= N - 1; i++) {
        std::cin >> city_name >> city_happiness;
        city_happiness_count[city_name] = city_happiness;
        city_index[city_name] = i;
    }
    std::map<int, std::string> reverse_city_index;
    for(const auto& city : city_index) {
        reverse_city_index.insert({city.second, city.first});
    }
    std::vector<std::vector<int>> graph(N, std::vector<int>(N, 0));
    std::string city_1, city_2;
    int city_1_index, city_2_index, cost;
    for(int i = 0; i < K; i++) {
        std::cin >> city_1 >> city_2 >> cost;
        city_1_index = city_index[city_1];
        city_2_index = city_index[city_2];
        graph[city_1_index][city_2_index] = cost;
        graph[city_2_index][city_1_index] = cost;
    }

    int target = city_index["ROM"];
    std::vector<bool> visited(N, false);
    std::vector<int> path;
    std::vector<std::vector<int>> all_paths;
    dfs_find_path(graph, 0, target, visited, path, all_paths);
    int min_cost = INT_MAX, sum_cost = 0, sum_happiness = 0, avg_happiness = 0;
    std::vector<std::tuple<std::vector<int>, int, int, int>> result_paths;
    int least_cost_count = 1;
    for(int i = 0; i < all_paths.size(); i++) {
        std::vector<int> path = all_paths[i];
        for(int j = 1; j < path.size(); j++) {
            int city_1 = path[j - 1];
            int city_2 = path[j];
            sum_cost += graph[city_1][city_2];
            sum_happiness += city_happiness_count[reverse_city_index[path[j]]];
        }
        if(sum_cost < min_cost) {
            min_cost = sum_cost;
            least_cost_count = 1;
        }else if(sum_cost == min_cost) {
            least_cost_count += 1;
        }
        avg_happiness = sum_happiness / (path.size() - 1);
        result_paths.push_back({path, sum_cost, sum_happiness, avg_happiness});
        sum_cost = 0;
        sum_happiness = 0;
    }

    std::sort(result_paths.begin(), result_paths.end(), [](std::tuple<std::vector<int>, int, int, int> a, std::tuple<std::vector<int>, int, int, int> b) {
        int sum_cost_a = std::get<1>(a), sum_cost_b = std::get<1>(b), sum_happiness_a = std::get<2>(a), sum_happiness_b = std::get<2>(b), avg_happiness_a = std::get<3>(a), avg_happiness_b = std::get<3>(b);
        if(sum_cost_a == sum_cost_b) {
            if(sum_happiness_a == sum_happiness_b) {
                return avg_happiness_a > avg_happiness_b;
            }
            return sum_happiness_a > sum_happiness_b;
        }
        return sum_cost_a < sum_cost_b;
    });

    auto [res_path, res_sum_cost, res_sum_happiness, res_avg_happiness] = result_paths[0];

    std::cout << least_cost_count << " " << res_sum_cost << " " << res_sum_happiness << " " << res_avg_happiness << std::endl;

    for(int i = 0; i < res_path.size(); i++) {
        if(i != res_path.size() - 1) {
            std::cout << reverse_city_index[res_path[i]] << "->";
        }else std::cout << reverse_city_index[res_path[i]] << std::endl;
    }

    return 0;
}