#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L, H;
    std::cin >> N >> L >> H;
    std::cin.ignore();

    std::vector<std::tuple<std::string, int, int>> vec_sage, vec_nobleman, vec_fool_man, vec_small_man;
    std::string ID_Number;
    int Virtue_Grade, Talent_Grade;

    for(int i = 0; i < N; i++) {
        std::cin >> ID_Number >> Virtue_Grade >> Talent_Grade;
        if(Virtue_Grade >= H && Talent_Grade >= H)  vec_sage.push_back({ID_Number, Virtue_Grade, Talent_Grade});
        else if(Virtue_Grade >= H && Talent_Grade < H && Talent_Grade >= L) vec_nobleman.push_back({ID_Number, Virtue_Grade, Talent_Grade});
        else if(Virtue_Grade < H && Talent_Grade < H && Virtue_Grade >= Talent_Grade && Talent_Grade >= L && Virtue_Grade >= L) vec_fool_man.push_back({ID_Number, Virtue_Grade, Talent_Grade});
        else if(Virtue_Grade >=L && Talent_Grade >= L && Talent_Grade > Virtue_Grade) vec_small_man.push_back({ID_Number, Virtue_Grade, Talent_Grade});
    }

    std::sort(vec_sage.begin(), vec_sage.end(), [](std::tuple<std::string, int, int> a, std::tuple<std::string, int, int> b) {
        if(std::get<1>(a) + std::get<2>(a) == std::get<1>(b) + std::get<2>(b)) {
            if(std::get<1>(a) == std::get<1>(b))
                return std::get<0>(a) < std::get<0>(b);
            else {
                return std::get<1>(a) > std::get<1>(b);
            }
        }else {
            return std::get<1>(a) + std::get<2>(a) > std::get<1>(b) + std::get<2>(b);
        }
    });

    std::sort(vec_nobleman.begin(), vec_nobleman.end(), [](std::tuple<std::string, int, int> a, std::tuple<std::string, int, int> b) {
        if(std::get<1>(a) + std::get<2>(a) == std::get<1>(b) + std::get<2>(b)) {
            if(std::get<1>(a) == std::get<1>(b))
                return std::get<0>(a) < std::get<0>(b);
            else {
                return std::get<1>(a) > std::get<1>(b);
            }
        }else {
            return std::get<1>(a) + std::get<2>(a) > std::get<1>(b) + std::get<2>(b);
        }
    });

    std::sort(vec_fool_man.begin(), vec_fool_man.end(), [](std::tuple<std::string, int, int> a, std::tuple<std::string, int, int> b) {
        if(std::get<1>(a) + std::get<2>(a) == std::get<1>(b) + std::get<2>(b)) {
            if(std::get<1>(a) == std::get<1>(b))
                return std::get<0>(a) < std::get<0>(b);
            else {
                return std::get<1>(a) > std::get<1>(b);
            }
        }else {
            return std::get<1>(a) + std::get<2>(a) > std::get<1>(b) + std::get<2>(b);
        }
    });

    std::sort(vec_small_man.begin(), vec_small_man.end(), [](std::tuple<std::string, int, int> a, std::tuple<std::string, int, int> b) {
        if(std::get<1>(a) + std::get<2>(a) == std::get<1>(b) + std::get<2>(b)) {
            if(std::get<1>(a) == std::get<1>(b))
                return std::get<0>(a) < std::get<0>(b);
            else {
                return std::get<1>(a) > std::get<1>(b);
            }
        }else {
            return std::get<1>(a) + std::get<2>(a) > std::get<1>(b) + std::get<2>(b);
        }
    });


    std::cout << vec_sage.size() + vec_nobleman.size() + vec_fool_man.size() + vec_small_man.size() << std::endl;
    for(int i = 0; i < vec_sage.size(); i++) {
        std::cout << std::get<0>(vec_sage[i]) << " " << std::get<1>(vec_sage[i]) << " " << std::get<2>(vec_sage[i]) << std::endl;
    }
    for(int i = 0; i < vec_nobleman.size(); i++) {
        std::cout << std::get<0>(vec_nobleman[i]) << " " << std::get<1>(vec_nobleman[i]) << " " << std::get<2>(vec_nobleman[i]) << std::endl;
    }
    for(int i = 0; i < vec_fool_man.size(); i++) {
        std::cout << std::get<0>(vec_fool_man[i]) << " " << std::get<1>(vec_fool_man[i]) << " " << std::get<2>(vec_fool_man[i]) << std::endl;
    }
    for(int i = 0; i < vec_small_man.size(); i++) {
        std::cout << std::get<0>(vec_small_man[i]) << " " << std::get<1>(vec_small_man[i]) << " " << std::get<2>(vec_small_man[i]) << std::endl;
    }

    return 0;
}