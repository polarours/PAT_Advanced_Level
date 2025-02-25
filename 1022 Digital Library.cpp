#include <bits/stdc++.h>

void StringSplit(std::string str, const char split,
                 std::vector<std::string> &result) {
  std::istringstream ss(str);
  std::string token;
  while (std::getline(ss, token, split)) {
    result.push_back(token);
  }
}

int main() {
  std::cout << std::unitbuf;

  int N;
  std::cin >> N;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::vector<std::tuple<int, std::string, std::string,
                         std::vector<std::string>, std::string, int>>
      library;

  int ID_number;
  std::string book_title, author, publisher, str_key_words;
  std::vector<std::string> key_words;
  int publisher_year;

  for (int i = 0; i < N; i++) {
    std::cin >> ID_number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, book_title);
    std::getline(std::cin, author);
    std::getline(std::cin, str_key_words);
    std::getline(std::cin, publisher);
    std::cin >> publisher_year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    StringSplit(str_key_words, ' ', key_words);
    auto t = std::make_tuple(ID_number, book_title, author, key_words,
                             publisher, publisher_year);
    library.push_back(t);
    key_words.clear();
  }
  int qurry_number;
  std::cin >> qurry_number;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string qurry_info;
  int index;
  while (qurry_number--) {
    std::getline(std::cin, qurry_info);
    index = qurry_info[0] - '0';
    std::string s = qurry_info.substr(3);

    std::cout << qurry_info << std::endl;

    std::vector<int> matched_ids; // 用于存储匹配的书籍 ID
    for (const auto& t : library) {
      if (index == 1) {
        std::string book_title = std::get<1>(t);
        if (book_title == s) {
          matched_ids.push_back(std::get<0>(t));
        }
      } else if (index == 2) {
        std::string author = std::get<2>(t);
        if (author == s) {
          matched_ids.push_back(std::get<0>(t));
        }
      } else if (index == 3) {
        std::vector<std::string> v = std::get<3>(t);
        std::string target = s;
        bool flag = std::find(v.begin(), v.end(), target) != v.end();
        if (flag) {
          matched_ids.push_back(std::get<0>(t));
        }
      } else if (index == 4) {
        std::string publisher = std::get<4>(t);
        if (publisher == s) {
          matched_ids.push_back(std::get<0>(t));
        }
      } else if (index == 5) {
        int publisher_year = std::get<5>(t);
        if (publisher_year == stoi(s)) {
          matched_ids.push_back(std::get<0>(t));
        }
      }
    }
    if(matched_ids.empty()) {
      std::cout << "Not Found" << std::endl;
    }else {
      std::sort(matched_ids.begin(), matched_ids.end());
      for(int id : matched_ids) {
        std::cout << std::setw(7) << std::setfill('0') << id << std::endl;
      }
    }
  }

  return 0;
}
