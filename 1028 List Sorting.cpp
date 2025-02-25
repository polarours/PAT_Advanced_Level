#include <bits/stdc++.h>

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, split)) {
        result.push_back(token);
    }
}

int main() {
    int N, C;
    std::cin >> N >> C;
    std::cin.ignore();

    std::tuple<std::string, std::string, int> t;
    std::vector<std::tuple<std::string, std::string, int>> recording_tuples;
    std::string s1, s2;
    int a;
    for (int i = 0; i < N; i++) {
        std::cin >> s1 >> s2 >> a;
        t = std::make_tuple(s1, s2, a);
        recording_tuples.push_back(t);
    }

    std::sort(recording_tuples.begin(), recording_tuples.end(), [C](std::tuple<std::string, std::string, int>& a, std::tuple<std::string, std::string, int>& b) {
        if(C == 1) {
            return std::get<0>(a) < std::get<0>(b);
        }else if(C == 2) {
            if(std::get<1>(a) == std::get<1>(b)) {
                return std::get<0>(a) < std::get<0>(b);
            }
            return std::get<1>(a) < std::get<1>(b);
        }else if(C == 3) {
            if(std::get<2>(a) == std::get<2>(b)) {
                return std::get<0>(a) < std::get<0>(b);
            }
            return std::get<2>(a) < std::get<2>(b);
        }
    });

    for(int i = 0; i < N; i++) {
        t = recording_tuples[i];
        std::cout << std::setw(6) << std::setfill('0') << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;
    }

    return 0;
}

