#include <bits/stdc++.h>

const int MAX = 100000;

typedef struct node {
    char data;
    int next;
    bool visited;
}Node;

int main() {
    int begin_1, begin_2, total_nodes_number;
    std::cin >> begin_1 >> begin_2 >> total_nodes_number;
    std::vector<Node> nodes(MAX);

    int address, next, result = -1;
    char data;
    for(int i = 0; i < total_nodes_number; i++) {
        std::cin >> address >> data >> next;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    for(int pos = begin_1; pos != -1; pos = nodes[pos].next) {
        nodes[pos].visited = true;
    }

    for(int pos = begin_2; pos != -1; pos = nodes[pos].next) {
        if(nodes[pos].visited) {
            result = pos;
            break;
        }
    }

    if(result == -1) {
        std::cout << -1 << std::endl;
    }else {
        std::cout << std::setw(5) << std::setfill('0') << result << std::endl;
    }

    return 0;
}