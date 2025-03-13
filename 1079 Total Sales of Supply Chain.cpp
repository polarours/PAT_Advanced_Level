#include <bits/stdc++.h>

struct Node {
    int level;
    int amount;
    std::vector<int> children;
    Node(){ level = 0;amount = 0; }
};

int main() {
    int N;
    double P, r;
    std::cin >> N >> P >> r;

    std::vector<Node> v(N);

    for(int i = 0; i < N; i++) {
        int count;
        std::cin >> count;
        if(count == 0) std::cin >> v[i].amount;
        else {
            while(count--) {
                int id;
                std::cin >> id;
                v[i].children.push_back(id);
            }
        }
    }

    std::queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur_id = q.front();
        q.pop();
        for(int i = 0; i < v[cur_id].children.size(); i++){
            v[v[cur_id].children[i]].level = v[cur_id].level + 1;
            q.push(v[cur_id].children[i]);
        }
    }

    double res = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i].amount != 0) {
            double cur_price = P * std::pow(1 + r / 100, v[i].level);
            res += cur_price * v[i].amount;
        }
    }

    std::cout << std::fixed << std::setprecision(1) << res << std::endl;

    return 0;
}