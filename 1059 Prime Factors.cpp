#include <bits/stdc++.h>

struct PrimeFactor {
    long int prime;
    int exponent;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long int N;
    std::cin >> N;

    long int num = N;
    std::vector<int> vec_prime;
    std::vector<PrimeFactor> prime_factors;

    for(long int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            PrimeFactor prime_factor = {i, 0};
            while(num % i == 0) {
                num /= i;
                prime_factor.exponent++;
            }
            prime_factors.push_back(prime_factor);
        }
    }
    if(num > 1) {
        vec_prime.push_back(num);
        prime_factors.push_back({num, 1});
    }

    std::cout << N << "=";
    if(prime_factors.empty()) {
        std::cout << N << std::endl;
        return 0;
    }
    for(auto it = prime_factors.begin(); it != prime_factors.end(); it++) {
        std::cout << it->prime;
        if(it->exponent > 1) {
            std::cout << "^" << it->exponent;
        }
        if(it == prime_factors.end() - 1)
            std::cout << std::endl;
        else
            std::cout << "*";
    }

    return 0;
}