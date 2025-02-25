#include <bits/stdc++.h>

struct Window {
  int end_time = 8 * 3600; // 只需要维护结束时间
};

struct Customer {
  std::string adjusted_time;
  int process_time;
  int original_seconds;
};

void StringSplit(const std::string &str, char split,
                 std::vector<std::string> &result) {
  std::istringstream ss(str);
  std::string token;
  while (std::getline(ss, token, split)) {
    result.push_back(token);
  }
}

int TimeToSeconds(const std::string &str) {
  std::vector<std::string> parts;
  StringSplit(str, ':', parts);
  return 3600 * std::stoi(parts[0]) + 60 * std::stoi(parts[1]) +
         std::stoi(parts[2]);
}

int main() {
  int N, K;
  std::cin >> N >> K;

  int valid_customers = 0;
  int total_wait = 0;
  std::vector<Customer> customers;
  std::vector<Window> windows(K);

  for (int i = 0; i < N; ++i) {
    std::string arrive_time;
    int process_time;
    std::cin >> arrive_time >> process_time;

    int original_sec = TimeToSeconds(arrive_time);
    int hour = original_sec / 3600;

    // 排除17:00及之后到达的客户
    if (hour >= 17)
      continue;

    // 处理时间限制并转换为秒
    process_time = std::min(process_time, 60) * 60;

    // 处理早于8点的客户
    if (hour < 8) {
      total_wait += 8 * 3600 - original_sec;
      arrive_time = "08:00:00";
    }

    customers.push_back({arrive_time, process_time, original_sec});
    valid_customers++;
  }

  // 按调整后时间排序，相同则按原始到达时间排序
  std::sort(customers.begin(), customers.end(),
            [](const Customer &a, const Customer &b) {
              int a_adj = TimeToSeconds(a.adjusted_time);
              int b_adj = TimeToSeconds(b.adjusted_time);
              return std::tie(a_adj, a.original_seconds) <
                     std::tie(b_adj, b.original_seconds);
            });

  for (const auto &customer : customers) {
    int arrival_sec = TimeToSeconds(customer.adjusted_time);
    int min_end = windows[0].end_time;
    int min_idx = 0;

    // 找到最早可用的窗口
    for (int i = 1; i < K; ++i) {
      if (windows[i].end_time < min_end) {
        min_end = windows[i].end_time;
        min_idx = i;
      }
    }

    // 计算等待时间
    if (arrival_sec < windows[min_idx].end_time) {
      total_wait += windows[min_idx].end_time - arrival_sec;
      windows[min_idx].end_time += customer.process_time;
    } else {
      windows[min_idx].end_time = arrival_sec + customer.process_time;
    }
  }

  if (valid_customers == 0) {
    std::cout << "0.0" << std::endl;
    return 0;
  }

  double avg_wait = static_cast<double>(total_wait) / 60 / valid_customers;
  std::cout << std::fixed << std::setprecision(1) << avg_wait << std::endl;

  return 0;
}
