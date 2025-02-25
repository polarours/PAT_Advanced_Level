#include <bits/stdc++.h>

using namespace std;

// DFS
void DFS(const vector<vector<int>> &adjMatrix, vector<bool> &visit, int v) {
  visit[v] = true;
  for (int i = 1; i <= adjMatrix.size(); i++) {
    if (i != v && adjMatrix[v][i] == 1 && !visit[i])
      DFS(adjMatrix, visit, i);
  }
}

int main() {
  int N, M, K; // N 城市总数，下标从1到N M 剩余的高速公路 K 需要检查的城市数
  cin >> N >> M >> K;
  vector<vector<int>> graph_cities(N + 1, vector<int>(N + 1, 0));
  vector<int> cities_concern;

  // 剩余的M条高速公路是哪些
  for (int i = 0; i < M; i++) {
    int city_A, city_B;
    cin >> city_A >> city_B;
    graph_cities[city_A][city_B] = 1;
    graph_cities[city_B][city_A] = 1;
  }

  // 需要关注的城市
  for (int i = 0; i < K; i++) {
    int city;
    cin >> city;
    cities_concern.push_back(city);
  }

  // 输出有N行
  // 分别讨论1到N城市失去后，需要修理的高速公路数，要求剩余的城市可以通过
  for (int i = 0; i < K; i++) {
    int count = 0;
    int cur_city = cities_concern[i];
    vector<vector<int>> adjMatrix =
        graph_cities; // 修正后的城市高速公路邻接矩阵
    vector<bool> visit(N + 1, false);
    for (int index = 1; index <= N; index++) {
      adjMatrix[cur_city][index] = 0;
      adjMatrix[index][cur_city] = 0;
    }
    visit[cur_city] = true;

    // 需要检查剩余的高速公路是否是连通图
    for (int i = 1; i <= N; i++) {
      if (i == cur_city)
        continue;
      if (!visit[i]) {
        DFS(adjMatrix, visit, i);
        count++;
      }
    }
    cout << count - 1 << endl;
  }

  return 0;
}
