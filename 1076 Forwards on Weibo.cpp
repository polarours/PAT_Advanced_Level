#include <bits/stdc++.h>

using namespace std;

struct user {
    int user_ID;
    std::vector<int> fans;
    std::vector<int> subscribe;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L;
    std::cin >> N >> L;
    std::map<int, std::vector<int>> user_to_fans;
    for (int i = 1; i <= N; i++) {
        int count, user_ID;
        std::cin >> count;
        while(count--) {
            std::cin >> user_ID;
            user_to_fans[user_ID].push_back(i);
        }
    }

    int query_count;
    std::cin >> query_count;
    std::vector<int> vec_query;
    while (query_count--) {
        int query_ID;
        std::cin >> query_ID;
        vec_query.push_back(query_ID);
    }

    std::vector<int> res;

    for(int i = 0; i < vec_query.size(); i++) {
        int query_ID = vec_query[i];
        int sum = 0;

        std::map<int, bool> user_visited;
        for(int cur_user = 1; cur_user <= L; cur_user++) {
            user_visited[cur_user] = false;
        }

        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(query_ID, 0));
        user_visited[query_ID] = true;

        while(!q.empty()) {
            int cur_user = q.front().first;
            int cur_level = q.front().second;
            q.pop();
            if(cur_level < L) {
                for(int user : user_to_fans[cur_user]) {
                    if(!user_visited[user]) {
                        sum++;
                        user_visited[user] = true;
                        q.push({user, cur_level + 1});
                    }
                }
            }
        }
        res.push_back(sum);
    }

    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}