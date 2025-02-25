
#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &graph, std::vector<int> &path,
         std::vector<std::vector<int>> &all_path, std::vector<bool> &visited, int current, int target) {
  path.push_back(current);
  visited[current] = true;
  if (current == target)
    all_path.push_back(path);
  else {
    for (size_t i = 0; i < graph.size(); i++)
      if (graph[current][i] != INT_MAX && !visited[i])
        dfs(graph, path, all_path,visited, static_cast<int>(i), target);
  }
  visited[current] = false;
  path.pop_back();
}

std::vector<std::vector<int>> find_path(std::vector<std::vector<int>> &graph,std::vector<bool> &visited,
                                        int start, int end) {
  std::vector<std::vector<int>> all_path;
  std::vector<int> path;
  dfs(graph, path, all_path,visited, start, end);
  return all_path;
}

int main() {
  int PMBC_send_bikes = INT_MAX, PMBC_send_times = INT_MAX, take_back_bikes = 0; // number of bikes
  std::vector<int> result_path;

  int C_max, N, S_p, M;
  std::cin >> C_max >> N >> S_p >> M;

  std::vector<int> cur_number_station(N + 1, 0);
  for (int i = 1; i <= N; i++)
    std::cin >> cur_number_station[i];

  std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, INT_MAX));
  for (int i = 1; i <= M; i++) {
    int S_i, S_j, T_ij;
    std::cin >> S_i >> S_j >> T_ij;
    graph[S_i][S_j] = T_ij;
    graph[S_j][S_i] = T_ij;
  }

  std::vector<bool> visited(N + 1, false);
  std::vector<std::vector<int>> all_path = find_path(graph, visited ,0, S_p);

  for (const auto &vec : all_path) {
    int sum_bikes = 0, sum_times = 0, send_bikes = 0, take_back = 0;
    for (int i = 0; i < vec.size(); i++)
      sum_bikes += cur_number_station[vec[i]];
    for (int i = 0; i < vec.size() - 1; i++)
      sum_times += graph[vec[i]][vec[i + 1]];
    int need = 0;
    for (int i = 1; i < vec.size(); i++) {
      int diff = C_max / 2 - cur_number_station[vec[i]];
      if(diff > 0)
        if(take_back >= diff)
          take_back -= diff;
        else {
          send_bikes += diff - take_back;
          take_back = 0;
        }
      else {
        take_back += abs(diff);
      }
    }
    if (sum_times < PMBC_send_times ||
           (sum_times == PMBC_send_times && send_bikes < PMBC_send_bikes) ||
           (sum_times == PMBC_send_times && send_bikes == PMBC_send_bikes && take_back < take_back_bikes)) {
      result_path = vec;
      PMBC_send_bikes = send_bikes;
      PMBC_send_times = sum_times;
      take_back_bikes = take_back;
           }
  }

  std::cout << PMBC_send_bikes << " ";
  for (int i = 0; i < result_path.size(); i++)
    if (i != result_path.size() - 1)
      std::cout << result_path[i] << "->";
    else
      std::cout << result_path[i] << " " << take_back_bikes << std::endl;

  return 0;
}
