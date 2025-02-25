#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cin.ignore();

    std::string name;
    int age, money;
    std::vector<std::tuple<std::string, int, int>> vec_person;
    for(int i = 0; i < N; i++) {
        std::cin >> name >> age >> money;
        vec_person.push_back(std::make_tuple(name, age, money));
    }

    int max_num = 0, age_min, age_max;
    std::vector<std::tuple<int, int, int>> vec_query;
    for(int i = 0; i < K; i++) {
        std::cin >> max_num >> age_min >> age_max;
        vec_query.push_back({max_num, age_min, age_max});
    }

    std::sort(vec_person.begin(), vec_person.end(), [](std::tuple<std::string, int, int> a, std::tuple<std::string, int, int> b) {
        auto [name1, age1, money1] = a;
        auto [name2, age2, money2] = b;
        if(money1 == money2) {
            if(age1 == age2) return name1 < name2;
            return age1 < age2;
        }
        return money1 > money2;
    });

    int index = 1;
    for(int i = 0; i < K; i++) {
        int count = 0;
        printf("%s%d%s\n", "Case #", index++, ":");
        auto [max_num, age_min, age_max] = vec_query[i];
        if(age_min > age_max) std::cout << "None" << std::endl;
        for(int j = 0; j < N; j++) {
            if(count == max_num) break;
            std::string name = std::get<0>(vec_person[j]);
            int age = std::get<1>(vec_person[j]), money = std::get<2>(vec_person[j]);
            if(age >= age_min && age <= age_max) {
                count += 1;
                printf("%s %d %d\n", name.c_str(), age, money);
            }
        }
        if(count == 0) std::cout << "None" << std::endl;
    }




    return 0;
}