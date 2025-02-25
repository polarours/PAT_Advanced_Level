#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> v(N);
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end(), [](std::string s1, std::string s2) {
        return s1 + s2 < s2 + s1;
    });

    std::string result = "";
    for(int i = 0; i < N; i++) {
        result += v[i];
    }
    int index = 0;
    for(int i = 0; i < result.size(); i++) {
        if(result[i] == '0') {
            index++;
        }else {
            break;
        }
    }

    result = index != result.size() ? result.substr(index, result.size()) : "0";
    std::cout << result << std::endl;

    return 0;
}