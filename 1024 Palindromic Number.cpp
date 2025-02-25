#include <bits/stdc++.h>

std::string create_palindromic(std::string str) {
  std::string palindromic = str;
  std::reverse(palindromic.begin(), palindromic.end());
  return palindromic;
}

bool is_palindromic(std::string str) {
  std::string palindromic = str;
  std::reverse(palindromic.begin(), palindromic.end());
  return palindromic == str;
}

std::string string_add(std::string s1, std::string s2) {
  std::string result;
  int carry = 0;
  int sum = 0;
  for (int i = s1.length() - 1; i >= 0; i--) {
    sum += (s1[i] - '0') + (s2[i] - '0') + carry;
    carry = sum / 10;
    sum = sum % 10;
    result.push_back(sum + '0');
    sum = 0;
  }
  if (carry > 0) {
    result.push_back(carry + '0');
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  std::string N;
  int K;
  std::cin >> N >> K;

  bool flag = false;
  std::string result, palindromic_num;
  int steps = 0;
  for (int i = 0; i < K; i++) {
    if (is_palindromic(N)) {
      flag = true;
      steps = i;
      result = N;
      break;
    }
    palindromic_num = create_palindromic(N); // string类型
    N = string_add(N, palindromic_num);
  }

  if (flag) {
    std::cout << result << std::endl;
    std::cout << steps << std::endl;
  } else {
    std::cout << N << std::endl;
    std::cout << K << std::endl;
  }

  return 0;
}
