#include <bits/stdc++.h>

int main() {

    int N, K;
    std::cin >> N >> K;

    std::vector<int> v(K + 1, 0);
    std::vector<std::vector<std::string>> vec_stu_course(K);
    for(int i = 0; i < N; i++) {
        std::string stu_name;
        std::cin >> stu_name;
        int stu_course_count;
        std::cin >> stu_course_count;
        for(int j = 0; j < stu_course_count; j++) {
            int course_id;
            std::cin >> course_id;
            v[course_id]++;
            vec_stu_course[course_id - 1].push_back(stu_name);
        }
    }

    for(int i = 0; i < K; i++) {
        std::sort(vec_stu_course[i].begin(), vec_stu_course[i].end());
    }

    for(int i = 0; i < K; i++) {
        std::cout << i + 1 << " " << v[i + 1] << std::endl;
        for(const auto& stu_name : vec_stu_course[i]) {
            printf("%s\n", stu_name.c_str());
        }
    }

    return 0;
}