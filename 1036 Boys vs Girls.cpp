#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int result_female_grades = INT_MIN, result_male_grades = INT_MAX;
    std::string result_female_name, result_female_id, result_male_name, result_male_id;
    std::string name, id, sex;
    int grades;
    for (int i = 0; i < N; i++) {
        std::cin >> name >> sex >> id >> grades;
        if(sex == "F") {
            if(grades > result_female_grades) {
                result_female_grades = grades;
                result_female_name = name;
                result_female_id = id;
            }
        }else {
            if(grades < result_male_grades) {
                result_male_grades = grades;
                result_male_name = name;
                result_male_id = id;
            }
        }
    }

    if(result_female_grades == INT_MIN) {
        std::cout << "Absent" << std::endl;
    }else {
        std::cout << result_female_name << " " << result_female_id << std::endl;
    }
    if(result_male_grades == INT_MAX) {
        std::cout << "Absent" << std::endl;
    }else {
        std::cout << result_male_name << " " << result_male_id << std::endl;
    }
    if(result_female_grades == INT_MIN || result_male_grades == INT_MAX) {
        std::cout << "NA" << std::endl;
    }else {
        std::cout << result_female_grades - result_male_grades << std::endl;
    }

    return 0;
}