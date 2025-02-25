#include <bits/stdc++.h>

int find_common(std::set<int>& s1, std::set<int>& s2) {
    int res = 0;
    auto it1 = s1.begin(), it2 = s2.begin();

    while (it1 != s1.end() && it2 != s2.end()) {
        if(*it1 == *it2) {
            res++;
            ++it1;
            ++it2;
        }else if(*it1 < *it2) {
            ++it1;
        }else {
            ++it2;
        }
    }

    return res;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::vector<std::set<int>> v(N);

    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        std::set<int> s;
        for (int j = 0; j < num; j++) {
            int n;
            std::cin >> n;
            s.insert(n);
        }
        v[i] = s;
        std::cin.ignore();
    }
    int query_number;
    std::cin >> query_number;
    std::vector<std::pair<int, int>> queries;
    for (int i = 0; i < query_number; i++) {
        int a, b;
        std::cin >> a >> b;
        queries.push_back(std::make_pair(a, b));
    }

    for(int i = 0; i < queries.size(); i++) {
        int a, b;
        a = queries[i].first - 1;
        b = queries[i].second - 1;
        std::set<int> s1 = v[a], s2 = v[b];
        int common = find_common(s1, s2);
        std::vector<int> vec;
        std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(vec));
        int size = vec.size();
        double d = static_cast<double>(common) / static_cast<double>(size) * 100.0;
        std::cout << std::fixed << std::setprecision(1) << d << "%" << std::endl;
    }

    return 0;
}