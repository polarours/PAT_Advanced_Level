#include<bits/stdc++.h>

bool is_insertion(std::vector<int>& arr, std::vector<int>& compare) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int j = i -1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
        if(arr == compare) {
            j = i;
            key = arr[i + 1];
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j -= 1;
            }
            arr[j + 1] = key;
            return true;
        }
    }
    return false;
}

bool is_merge(std::vector<int>& arr, std::vector<int>& compare) {
    int n = arr.size();
    for(int step = 1; step < n; step *= 2) {
        for(int i = 0; i < n; i += 2 * step) {
            int mid = std::min(i + step, n);
            int right = std::min(i + 2 * step, n);
            std::sort(arr.begin() + i, arr.begin() + right);
        }
        if(arr == compare) {
            step *= 2;
            for(int i = 0; i < n; i += 2 * step) {
                int mid = std::min(i + step, n);
                int right = std::min(i + 2 * step, n);
                std::sort(arr.begin() + i, arr.begin() + right);
            }
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> init_seq(N), partial_order_seq(N);
    for(int i = 0; i < N; i++) {
        std::cin >> init_seq[i];
    }
    for(int i = 0; i < N; i++) {
        std::cin >> partial_order_seq[i];
    }

    std::vector<int> vec_1 = init_seq, vec_2 = init_seq;
    if(is_insertion(vec_1, partial_order_seq)) {
        std::cout << "Insertion Sort" << std::endl;
        for(int i = 0; i < N; i++) {
            if(i != N - 1) {
                std::cout << vec_1[i] << " ";
            }else {
                std::cout << vec_1[i] << std::endl;
            }
        }
    }
    if(is_merge(vec_2, partial_order_seq)) {
        std::cout << "Merge Sort" << std::endl;
        for(int i = 0; i < N; i++) {
            if(i != N - 1) {
                std::cout << vec_2[i] << " ";
            }else {
                std::cout << vec_2[i] << std::endl;
            }
        }
    }

    return 0;
}