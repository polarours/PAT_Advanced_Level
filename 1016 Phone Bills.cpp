#include <bits/stdc++.h>

// 字符串分割函数
void StringSplit(const std::string &str, char split,
                 std::vector<std::string> &res) {
  std::istringstream ss(str);
  std::string token;
  while (std::getline(ss, token, split)) {
    res.push_back(token);
  }
}

// 比较时间字符串的函数
bool compareTime(const std::string &s1, const std::string &s2) {
  return s1 < s2;
}

// 计算通话费用的函数
double calculateCost(const std::vector<int> &time_cost,
                     const std::string &start, const std::string &end) {
  std::vector<std::string> startParts, endParts;
  StringSplit(start, ':', startParts);
  StringSplit(end, ':', endParts);

  int startDay = std::stoi(startParts[1]);
  int startHour = std::stoi(startParts[2]);
  int startMinute = std::stoi(startParts[3]);
  int endDay = std::stoi(endParts[1]);
  int endHour = std::stoi(endParts[2]);
  int endMinute = std::stoi(endParts[3]);

  double cost = 0;
  int duration = 0;

  // 模拟每分钟计费
  while (startDay < endDay || startHour < endHour || startMinute < endMinute) {
    cost += time_cost[startHour];
    startMinute++;
    duration++;
    if (startMinute == 60) {
      startMinute = 0;
      startHour++;
      if (startHour == 24) {
        startHour = 0;
        startDay++;
      }
    }
  }

  return cost / 100.0;
}

// 计算通话时长（分钟）
int calculateDuration(const std::string &start, const std::string &end) {
  std::vector<std::string> startParts, endParts;
  StringSplit(start, ':', startParts);
  StringSplit(end, ':', endParts);

  int startDay = std::stoi(startParts[1]);
  int startHour = std::stoi(startParts[2]);
  int startMinute = std::stoi(startParts[3]);
  int endDay = std::stoi(endParts[1]);
  int endHour = std::stoi(endParts[2]);
  int endMinute = std::stoi(endParts[3]);

  int totalStartMinutes = startDay * 24 * 60 + startHour * 60 + startMinute;
  int totalEndMinutes = endDay * 24 * 60 + endHour * 60 + endMinute;

  return totalEndMinutes - totalStartMinutes;
}

int main() {
  std::vector<int> time_cost(24, 0);
  // 输入每小时费用
  for (int i = 0; i < 24; i++) {
    std::cin >> time_cost[i];
  }

  int phone_times;
  std::cin >> phone_times;

  std::map<std::string, std::vector<std::pair<std::string, std::string>>>
      user_records;

  // 输入通话记录
  for (int i = 0; i < phone_times; i++) {
    std::string user_name, user_talk, user_talk_tag;
    std::cin >> user_name >> user_talk >> user_talk_tag;
    user_records[user_name].emplace_back(user_talk, user_talk_tag);
  }

  // 对每个用户的通话记录进行处理
  for (auto &user : user_records) {
    std::string user_name = user.first;
    auto &records = user.second;
    std::sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
      return compareTime(a.first, b.first);
    });

    std::vector<std::pair<std::string, std::string>> valid_calls;
    for (size_t i = 0; i < records.size() - 1; i++) {
      if (records[i].second == "on-line" &&
          records[i + 1].second == "off-line") {
        valid_calls.emplace_back(records[i].first, records[i + 1].first);
        i++;
      }
    }

    if (valid_calls.empty())
      continue;

    std::vector<std::string> parts;
    StringSplit(valid_calls[0].first, ':', parts);
    std::string month = parts[0];

    std::cout << user_name << " " << std::setfill('0') << std::setw(2) << month
              << std::endl;

    double total_cost = 0;
    for (const auto &call : valid_calls) {
      std::string start = call.first;
      std::string end = call.second;
      int duration = calculateDuration(start, end);
      double cost = calculateCost(time_cost, start, end);
      total_cost += cost;

      std::vector<std::string> startParts, endParts;
      StringSplit(start, ':', startParts);
      StringSplit(end, ':', endParts);

      std::cout << startParts[1] << ":" << startParts[2] << ":" << startParts[3]
                << " " << endParts[1] << ":" << endParts[2] << ":"
                << endParts[3] << " " << duration << " $" << std::fixed
                << std::setprecision(2) << cost << std::endl;
    }
    std::cout << "Total amount: $" << std::fixed << std::setprecision(2)
              << total_cost << std::endl;
  }

  return 0;
}
