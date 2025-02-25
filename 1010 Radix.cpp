#include <bits/stdc++.h>

using namespace std;

// convert函数转换目标进制数字
long long convert(string s, long long radix) {
  long long res = 0;
  int index = 0, temp = 0;
  for (auto it = s.rbegin(); it != s.rend(); it++) {
    temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
    res += temp * pow(radix, index++);
  }
  return res;
}

long long find_radix(string s, long long num) {
  char it = *max_element(s.begin(), s.end());
  long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
  long long high = max(num, low);
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long cur_num = convert(s, mid);
    if (cur_num < 0 || cur_num > num)
      high = mid - 1;
    else if (cur_num == num)
      return mid;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  string N1, N2;
  long long tag, radix, result;
  cin >> N1 >> N2 >> tag >> radix;
  long long num = tag == 1 ? convert(N1, radix) : convert(N2, radix);
  result = tag == 1 ? find_radix(N2, num) : find_radix(N1, num);
  if (result != -1)
    cout << result << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}
