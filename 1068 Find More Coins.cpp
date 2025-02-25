#include <bits/stdc++.h>

bool flag = false;
std::vector<int> res;

void dfs(std::vector<int>& arr, int index, int target, std::vector<int>& current) {
    if(target == 0) {
        if(!flag) {
            res = current;
            flag = true;
        }
        return;
    }
    if(index >= arr.size() || target < 0 || flag) {
        return;
    }
    if(target < arr[index]) {
        return;
    }
    current.push_back(arr[index]);
    dfs(arr, index + 1, target - arr[index], current);
    current.pop_back();
    dfs(arr, index + 1, target, current);
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
     if(sum < M) {
        std::cout << "No Solution" << std::endl;
        return 0;
    }
    std::vector<int> current;
    std::sort(arr.begin(), arr.end());
    dfs(arr, 0, M, current);

    
    if(flag) {
        for(int i = 0; i < res.size(); i++) {
            if(i != res.size() - 1) {
                std::cout << res[i] << " ";
            }else {
                std::cout << res[i] << std::endl;
            }
        }
    }else {
        std::cout << "No Solution" << std::endl;
    }

    return 0;
}