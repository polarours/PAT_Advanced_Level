#include<bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    int res = 0;    
    std::vector<int> price(N);
    std::vector<int> preSum(N + 1, 0);
    for(int i = 0; i < N; i++){
        std::cin >> price[i];
        if(price[i] <= M) res++;
    }
    for(int i = 1; i <= N; i++){
        preSum[i] = preSum[i - 1] + price[i - 1];
    }

    for(int i = 1; i <= N - 1; i++){
        for(int j = i + 1; j <= N; j++){
            if(preSum[j] - preSum[i - 1] <= M) res++;
            else break;
        }
    }
    
    std::cout << res << std::endl;

    return 0;
}