#include <bits/stdc++.h>

int main() {
  int N, K;

  std::cin >> N;
  std::vector<std::tuple<std::string, int, int, int, int>> rank_info;
  std::vector<std::pair<std::string, int>> rank_pairs;
  for (int i = 1; i <= N; i++) {
    std::cin >> K;
    int location_number = i;
    std::string ID;
    int test;

    for (int j = 0; j < K; j++) {
      std::cin >> ID >> test;
      auto p = std::make_pair(ID, test);
      rank_pairs.push_back(p);
    }

    std::sort(rank_pairs.begin(), rank_pairs.end(),
              [](const std::pair<std::string, int> &p1,
                 const std::pair<std::string, int> &p2) {
                if (p1.second == p2.second) {
                  return p1.first < p2.first;
                }
                return p1.second > p2.second;
              });

    int local_rank = 1;
    int same_score_count = 1;
    auto t = std::make_tuple(rank_pairs[0].first, 0, location_number, 1,
                             rank_pairs[0].second);
    rank_info.push_back(t);
    for (int i = 1; i < rank_pairs.size(); i++) {
      auto [id1, t1] = rank_pairs[i - 1];
      auto [id2, t2] = rank_pairs[i];
      std::string ID = rank_pairs[i].first;
      int test = rank_pairs[i].second;
      std::tuple<std::string, int, int, int, int> t;
      if (t1 == t2) {
        same_score_count++;
      } else {
        local_rank += same_score_count;
        same_score_count = 1;
      }
      t = std::make_tuple(ID, 0, location_number, local_rank, test);
      rank_info.push_back(t);
    }
    rank_pairs.clear();
  }

  std::sort(rank_info.begin(), rank_info.end(),
            [](const std::tuple<std::string, int, int, int, int> &p1,
               const std::tuple<std::string, int, int, int, int> &p2) {
              if (std::get<4>(p1) == std::get<4>(p2)) {
                return std::get<0>(p1) < std::get<0>(p2);
              }
              return std::get<4>(p1) > std::get<4>(p2);
            });

  std::cout << rank_info.size() << std::endl;
  int final_rank = 1;
  int same_total_score_count = 1;
  std::cout << std::get<0>(rank_info[0]) << " " << 1 << " "
            << std::get<2>(rank_info[0]) << " " << std::get<3>(rank_info[0])
            << std::endl;
  for (int i = 1; i < rank_info.size(); i++) {
    auto [a1, b1, c1, d1, e2] = rank_info[i - 1];
    auto [a2, b2, c2, d2, e3] = rank_info[i];
    if (e2 == e3) {
      same_total_score_count++;
    } else {
      final_rank += same_total_score_count;
      same_total_score_count = 1;
    }
    std::cout << std::get<0>(rank_info[i]) << " " << final_rank << " "
              << std::get<2>(rank_info[i]) << " " << std::get<3>(rank_info[i])
              << std::endl;
  }

  return 0;
}
