#include <bits/stdc++.h>

int main() {
    int Nv, Ne;
    std::cin >> Nv >> Ne;

    std::vector<std::vector<int>> graph(Nv + 1, std::vector<int>(Nv + 1, 0));
    int vertices_A, vertices_B;
    for(int i = 0; i < Ne; i++) {
        std::cin >> vertices_A >> vertices_B;
        graph[vertices_A][vertices_B] = 1;
        graph[vertices_B][vertices_A] = 1;
    }

    std::vector<std::string> res;
    int query_num, K;
    std::cin >> query_num;
    for(int i = 0; i < query_num; i++) {
        std::cin >> K;
        std::vector<int> queries(K);
        for(int j = 0; j < K; j++) {
           std::cin >> queries[j];
        }

        bool is_clique = true;
        //判断是否为clique
        for(int p = 0; p < K - 1; p++) {
            for(int q = p + 1; q < K; q++) {
                if(graph[queries[p]][queries[q]] != 1) {
                    is_clique = false;
                    break;
                }
            }
            if(!is_clique) break;
        }

        if(!is_clique) {
            res.push_back("Not a Clique");
            continue;
        }

        //判断是否为最大
        bool is_maximal = true;
        for(int m = 1; m <= Nv; m++) {
            int cur_index = 0;
            for(int n = 0; n < K; n++) {
                if(graph[m][queries[n]] == 1 && std::find(queries.begin(), queries.end(), m) == queries.end()) {
                    cur_index++;
                }
            }
            if(cur_index == K) {
                is_maximal = false;
                break;
            }
        }

        if(is_maximal) res.push_back("Yes");
        else res.push_back("Not Maximal");

    }

    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }


    return 0;
}