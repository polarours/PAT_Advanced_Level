#include <bits/stdc++.h>

using namespace std;

int main() {

  int N, M, C1, C2;
  cin >> N >> M >> C1 >> C2;
  vector<int> weight(N, 0); // 每个城市有多少救援人员

  // 救援人员初始化
  for (int i = 0; i < N; i++)
    cin >> weight[i];

  vector<vector<int>> edge(N, vector<int>(N, INT_MAX));
  vector<int> distance(N, INT_MAX); // 到任一城市的距离
  vector<int> roads(N, 0);          // C1和C2之间不同的最短路径的数量
  vector<int> teams(N, 0);          // 到任一城市的距离救援队的数量
  vector<bool> visit(N, false);     // 是否访问过某个城市

  // 初始化权值表
  int c1, c2, l;
  for (int i = 0; i < M; i++) {
    cin >> c1 >> c2 >> l;
    edge[c1][c2] = l;
    edge[c2][c1] = l;
  }
  distance[C1] = 0;
  teams[C1] = weight[C1];
  roads[C1] = 1;

  // 核心代码
  for (int i = 0; i < N; i++) {
    int minDistance = INT_MAX, minNode = -1; // 最小距离以及最小距离的编号
    for (int j = 0; j < N; j++) {
      if (distance[j] < minDistance && !visit[j]) {
        minDistance = distance[j];
        minNode = j;
      }
    }
    if (minNode == -1)
      break;
    visit[minNode] = true;
    for (int curNode = 0; curNode < N; curNode++) {
      // 如果curNode点未被访问，且minNode到curNode有路径，则有可能刷新最短路径
      if (!visit[curNode] && edge[minNode][curNode] != INT_MAX) {
        if (distance[minNode] + edge[minNode][curNode] < distance[curNode]) {
          distance[curNode] = edge[minNode][curNode] + distance[minNode];
          roads[curNode] = roads[minNode];
          teams[curNode] = teams[minNode] + weight[curNode];
        } else if (distance[minNode] + edge[minNode][curNode] ==
                   distance[curNode]) { // 存在权重相同但路径不同的方案
          roads[curNode] = roads[minNode] + roads[curNode];
          // 如果救援人员更多，则更新
          if (teams[minNode] + weight[curNode] > teams[curNode])
            teams[curNode] = teams[minNode] + weight[curNode];
        }
      }
    }
  }

  cout << roads[C2] << " " << teams[C2] << endl;

  return 0;
}
