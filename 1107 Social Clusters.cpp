#include<bits/stdc++.h>

int parent[1010] = {0}, hobby[1010] = {0};

int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    parent[x_root] = y_root;
}

int main() {
    int N;
    std::cin >> N;

    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int K, hobby_index;
    for(int i = 1; i <= N; i++) {
        scanf("%d: ", &K);
        while(K--) {
            std::cin >> hobby_index;
            if(hobby[hobby_index] == 0) {
                hobby[hobby_index] = i;
            }else {
                Union(i, hobby[hobby_index]);
            }
        }
    }

    std::vector<int> res(N + 1, 0);
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(find(i) == i) cnt++;
        res[find(i)]++;
    }

    std::sort(res.begin(), res.end(), std::greater<int>());
    std::cout << cnt << std::endl;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt - 1)
            std::cout << res[i] << " ";
        else
            std::cout << res[i] << std::endl;
    }

    
    return 0;
}