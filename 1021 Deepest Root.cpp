#include <bits/stdc++.h>

void dfs_connected(const std::vector<std::vector<int>>& graph, int vertex, std::vector<bool>& visited) {
  visited[vertex] = true;
  for(int neighbour : graph[vertex]) {
    if(!visited[neighbour]) {
      dfs_connected(graph, neighbour, visited);
    }
  }
}

int countConnectedComponents_dfs(std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  int count = 0;
  std::vector<bool> visited(n, false);
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      count += 1;
      dfs_connected(graph, i, visited);
    }
  }
  return count;
}

void dfs(const std::vector<std::vector<int>> &graph, int current,
         int path_length, int &max_length, std::vector<int> &current_path,
         std::set<int> &max_paths_start, std::vector<bool> &visit) {
  visit[current] = true;
  current_path.push_back(current);

  if (path_length > max_length) {
    max_length = path_length;
    max_paths_start.clear();
    max_paths_start.insert(current_path[0]);
  } else if (path_length == max_length) {
    max_paths_start.insert(current_path[0]);
  }

  for (int neighbour : graph[current]) {
    if (!visit[neighbour]) {
      dfs(graph, neighbour, path_length + 1, max_length, current_path, max_paths_start,
          visit);
    }
  }

  visit[current] = false;
  current_path.pop_back();
}

std::set<int> count_path_length(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  int max_length = 0;
  std::set<int> all_max_paths;

  for (int i = 0; i < n; i++) {
    std::vector<bool> visit(n, false);
    std::vector<int> current_path;
    int total_length = 0;
    std::set<int> local_max_paths;
    dfs(graph, i, 0, total_length, current_path, local_max_paths, visit);
    if (total_length > max_length) {
      max_length = total_length;
      all_max_paths = local_max_paths;
    } else if (total_length == max_length) {
      all_max_paths.insert(local_max_paths.begin(),local_max_paths.end());
    }
  }

  return all_max_paths;
}

int main() {
  int N;
  std::cin >> N;

  std::vector<std::vector<int>> graph(N);
  std::vector<bool> visit(N, false);
  for (int i = 0; i < N - 1; i++) {
    int P_i, P_j;
    std::cin >> P_i >> P_j;
    P_i -= 1;
    P_j -= 1;
    graph[P_i].push_back(P_j);
    graph[P_j].push_back(P_i);
  }

  int count = countConnectedComponents_dfs(graph);
  if (count > 1) {
    std::cout << "Error: " << count << " " << "components" << std::endl;
    return 0;
  }

  std::set<int> all_max_path_starts = count_path_length(graph);
  for (const auto& p : all_max_path_starts) {
    std::cout << p + 1 << std::endl;
  }

  return 0;
}
