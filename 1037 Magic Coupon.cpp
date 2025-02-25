#include <bits/stdc++.h>

int main() {
    int N_c, N_p;

    std::cin >> N_c;
    std::vector<int> vec_coupon(N_c);
    for (int i = 0; i < N_c; i++) {
        std::cin >> vec_coupon[i];
    }
    std::cin >> N_p;
    std::vector<int> vec_product(N_p);
    for (int i = 0; i < N_p; i++) {
        std::cin >> vec_product[i];
    }

    std::sort(vec_coupon.begin(), vec_coupon.end());
    std::sort(vec_product.begin(), vec_product.end());

    int left_coupon = 0, right_coupon = N_c - 1, left_product = 0, right_product = N_p - 1;
    int result = 0;
    while(left_coupon <= right_coupon && left_product <= right_product) {
        int left_num = vec_coupon[left_coupon] * vec_product[left_product];
        int right_num = vec_coupon[right_coupon] * vec_product[right_product];
        if(left_num < 0 && right_num < 0) {
            break;
        }else if(left_num < 0 && right_num >= 0) {
            result += right_num;
            right_coupon--;
            right_product--;
        }else if(left_num >= 0 && right_num < 0) {
            result += left_num;
            left_coupon++;
            left_product++;
        }else if(left_num >= 0 && right_num >= 0) {
            if(left_num < right_num) {
                result += right_num;
                right_coupon--;
                right_product--;
            }else {
                result += left_num;
                left_coupon++;
                left_product++;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}