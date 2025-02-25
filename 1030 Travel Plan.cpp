#include <bits/stdc++.h>

void dfs(std::vector<std::vector<std::pair<int, int>>> &graph, std::vector<bool>& visited, std::vector<int>& path, std::vector<std::vector<int>>& all_paths, int current, int target) {
    visited[current] = true;
    path.push_back(current);
    if(current == target) {
        all_paths.push_back(path);
    }
    for (int i = 0; i < graph[current].size(); i++) {
        auto value = graph[current][i];
        if(value.first != 0 && value.second != 0 && !visited[i]) {
            dfs(graph, visited, path, all_paths, i, target);
        }
    }
    visited[current] = false;
    path.pop_back();
}

int main() {
    int N, M, S, D;
    std::cin >> N >> M >> S >> D;

    int c1, c2 , distance, cost;
    std::vector<std::vector<std::pair<int, int>>> graph(M, std::vector<std::pair<int, int>>(M, {0, 0}));
    for(int i = 0; i < M; i++) {
        std::cin >> c1 >> c2 >> distance >> cost;
        std::pair<int, int> edge = std::make_pair(distance, cost);
        graph[c1][c2] = edge;
        graph[c2][c1] = edge;
    }

    std::vector<bool> visited(N, false);
    std::vector<int> path;
    std::vector<std::vector<int>> all_paths;
    dfs(graph, visited, path, all_paths, S, D);

    std::vector<int> result;
    int min_cost = INT_MAX, min_distance = INT_MAX, cur_distance = 0, cur_cost = 0;
    for(int i = 0; i < all_paths.size(); i++) {
        cur_distance = cur_cost = 0;
        std::pair<int, int> cur_pair;
        std::vector<int> cur_path = all_paths[i];
        for(int j = 0; j < cur_path.size() - 1; j++) {
            cur_pair = graph[cur_path[j]][cur_path[j + 1]];
            cur_distance += cur_pair.first;
            cur_cost += cur_pair.second;
        }
        if(cur_distance < min_distance && cur_cost < min_cost) {
            min_distance = cur_distance;
            min_cost = cur_cost;
            result = cur_path;
        }else if(cur_distance < min_distance && cur_cost == min_cost) {
            min_distance = cur_distance;
            min_cost = cur_cost;
            result = cur_path;
        }else if(cur_distance < min_distance && cur_cost > min_cost) {
            min_distance = cur_distance;
            min_cost = cur_cost;
            result = cur_path;
        }else if(cur_distance == min_distance && cur_cost == min_cost) {
            min_distance = cur_distance;
            min_cost = cur_cost;
            result = cur_path;
        }else if(cur_distance == min_distance && cur_cost < min_cost) {
            min_distance = cur_distance;
            min_cost = cur_cost;
            result = cur_path;
        }
    }

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << min_distance << " " << min_cost << std::endl;

    return 0;
}