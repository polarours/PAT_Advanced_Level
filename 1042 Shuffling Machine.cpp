#include <bits/stdc++.h>

const std::vector<std::string> ans = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
"J1","J2"};

int main() {
    int K, num;
    std::cin >> K;

    std::vector<int> result, shuffle_vec;
    for(int i = 1; i <= 54; i++) {
        std::cin >> num;
        shuffle_vec.push_back(num);
        result.push_back(i);
    }

    while (K--) {
        std::vector<int> vec(54);
        for(int i = 0; i < shuffle_vec.size(); i++) {
            int pos = shuffle_vec[i];
            vec[pos - 1] = result[i];
        }
        result = vec;
    }

    for(int i = 0; i < result.size(); i++) {
        if(i != result.size() - 1) {
            std::cout << ans[result[i] - 1] << " ";
        }else {
            std::cout << ans[result[i] - 1] << std::endl;
        }
    }

    return 0;
}