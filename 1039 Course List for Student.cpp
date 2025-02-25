#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::map<std::string, std::vector<int>> map_stu;
    std::vector<std::string> vec_query;

    int course_id, stu_num;
    for(int i = 0; i < K; i++) {
        std::cin >> course_id >> stu_num;
        std::string stu_name;
        for(int i = 0; i < stu_num; i++) {
            std::cin >> stu_name;
            map_stu[stu_name].push_back(course_id);
        }
    }

    for(int i = 0; i < N; i++) {
        std::string name;
        std::cin >> name;
        vec_query.push_back(name);
    }

    for(int i = 0; i < N; i++) {
        std::vector<int> v = map_stu[vec_query[i]];
        std::sort(v.begin(), v.end());
        if(v.empty())
            std::cout << vec_query[i] << " " << map_stu[vec_query[i]].size() <<std::endl;
        else
            std::cout << vec_query[i] << " " << map_stu[vec_query[i]].size() << " ";
        for(int i = 0; i < v.size(); i++) {
            if(i != v.size() - 1)
                std::cout << v[i] << " ";
            else
                std::cout << v[i] << std::endl;
        }
    }

    return 0;
}