#include<bits/stdc++.h>

bool checkSequence(int M, int N, const std::vector<int>& seq) {
    std::stack<int> s;
    int current = 0;

    for(int num = 1; num <= N; num++) {
        s.push(num);
        if(s.size() > M) return false;

        while(!s.empty() && s.top() == seq[current]) {
            s.pop();
            current++;
        }
    }

    return current == N;
}

int main() {
    int M, N, K;
    std::cin >> M >> N >> K;

    std::vector<int> sequence(N);
    for (int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> sequence[j];
        }

        if(checkSequence(M, N, sequence)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}