#include <bits/stdc++.h>

int main() {
    int N, p;
    std::cin >> N >> p;

    int result = 0;
    std::vector<long int> nums(N);
    for(int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

   for(int left = 0, right = 0; right < N; right++) {
       while(nums[right] > nums[left] * p) left++;
       result = std::max(result, right - left + 1);
   }

    std::cout << result << std::endl;

    return 0;
}