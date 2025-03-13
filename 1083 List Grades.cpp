#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<std::string, std::string, int>> stu;
    std::string name, id;
    int grade;
    for (int i = 0; i < N; i++) {
        std::cin >> name >> id >> grade;
        stu.push_back({name, id, grade});
    }

    int grade_1, grade_2;
    std::cin >> grade_1 >> grade_2;

    std::vector<std::tuple<std::string, std::string, int>> result;
    for (int i = 0; i < N; i++) {
        auto [name, id, grade] = stu[i];
        if(grade >= grade_1 && grade <= grade_2) {
            result.push_back({name, id, grade});
        }
    }

    std::sort(result.begin(), result.end(), [](std::tuple<std::string, std::string, int> a, std::tuple<std::string, std::string, int> b) {
        return std::get<2>(a) > std::get<2>(b);
    });

    if(result.size() > 0) {
        for(int i = 0; i < result.size(); i++) {
            auto [name, id, grade] = result[i];
            std::cout << name << " " << id << std::endl;
        }
    }else {
        std::cout << "NONE" << std::endl;
    }

    return 0;
}