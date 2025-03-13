#include<bits/stdc++.h>

int main(){
    int N;
    double P, r;
    std::cin >> N >> P >> r;

    std::unordered_map<int, int> level;
    std::unordered_map<int, std::vector<int>> m;

    for(int i = 0; i < N; i++){
        level[i] = INT_MAX;
    }
    
    int K;
    std::vector<int> retailer;
    for(int i = 0; i < N; i++){
        std::cin >> K;
        int n;
        if(K == 0){
            retailer.push_back(i);
        }
        while(K--){
            std::cin >> n;
            m[i].push_back(n);
        }
    }

    std::queue<int> q;
    q.push(0);
    level[0] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        std::vector<int> v = m[cur];
        if(!v.empty()){
            for(const auto& num : v){
                level[num] = level[cur] + 1;
                q.push(num);
            }
        }
    }

    int minLevel = INT_MAX;
    int minLevlNums = 0;    
    for(const auto& index : retailer){
        if(level[index] < minLevel){
            minLevel = level[index];
            minLevlNums = 1;
        }else if(level[index] == minLevel){
            minLevlNums++;
        }
    }

    double res = P * std::pow(1 + r / 100, minLevel);
    std::cout << std::fixed << std::setprecision(4) << res << " " << minLevlNums << std::endl;
    
    return 0;
}