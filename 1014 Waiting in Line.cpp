#include <bits/stdc++.h>

int main() {
  int N, M, K, Q;
  std::cin >> N >> M >> K >> Q;
  std::vector<int> sum(N + 1, 0); // 每个窗口的结束时间
  std::vector<int> cost_time(K + 1, 0);
  std::unordered_map<int, int> map;
  std::queue<int> queue_window[N + 1]; // 每个窗口的客户队列

  for (int i = 1; i <= K; i++) {
    int time;
    std::cin >> time;
    cost_time[i] = time;
  }

  for (int cur_customer = 1; cur_customer <= K; cur_customer++) {
    int shortest_window = 1;
    for (int cur_window = 1; cur_window <= N; cur_window++) {
      if (cur_customer <= N * M) {
        // 窗口从小到大，找到队列长度最小的
        if (queue_window[cur_window].size() <
            queue_window[shortest_window].size())
          shortest_window = cur_window;
      } else {
        // 黄线内人数已满，需要找到最早结束的队列
        if (queue_window[cur_window].front() <
            queue_window[shortest_window].front())
          shortest_window = cur_window;
      }
    }

    sum[shortest_window] += cost_time[cur_customer]; // 此时是结束时间
    if (cur_customer > N * M)
      queue_window[shortest_window].pop();
    queue_window[shortest_window].push(sum[shortest_window]);
    if (sum[shortest_window] - cost_time[cur_customer] <
        540) // 只能在17:00前办理新业务
      map[cur_customer] = sum[shortest_window];
  }

  while (Q--) {
    int cur_qurry;
    std::cin >> cur_qurry;
    if (map.count(cur_qurry))
      std::cout << std::setw(2) << std::setfill('0') << 8 + map[cur_qurry] / 60
                << ":" << std::setw(2) << std::setfill('0')
                << map[cur_qurry] % 60 << std::endl;
    else
      std::cout << "Sorry" << std::endl;
  }

  return 0;
}
