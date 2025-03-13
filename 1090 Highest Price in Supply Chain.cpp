#include<bits/stdc++.h>

struct Node {
    int index;
    int level;
    std::vector<int> children;
    Node(int index, int level) {
        this->index = index;
        this->level = level;
    }
    Node() {
        this->index = 0;
        this->level = 0;
    }
};

int main() {
    int N;
    double P, r;
    std::cin >> N >> P >> r;

    int root_index = 0;
    std::vector<int> suppliers(N);
    std::unordered_map<int, std::vector<int>> supplier_map;
    for (int i = 0; i < N; i++) {
        std::cin >> suppliers[i];
        if(suppliers[i] == -1) root_index = i;
    }

    Node* root = new Node(root_index, 0);
    for(int i = 0; i < N; i++) {
        if(i != root_index)
        supplier_map[suppliers[i]].push_back(i);
    }
    root->children = supplier_map[root_index];
    std::vector<Node*> nodes;
    nodes.push_back(root);
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* cur_node = q.front();
        q.pop();
        for(int child_index : supplier_map[cur_node->index]) {
            Node* curNode = new Node(child_index, cur_node->level + 1);
            nodes.push_back(curNode);
            q.push(curNode);
        }
    }

    int max_level = INT_MIN, count = 0;
    for(int i = 0; i < nodes.size(); i++) {
        if(nodes[i]->level > max_level) {
            max_level = nodes[i]->level;
            count = 1;
        }else if(nodes[i]->level == max_level) {
            count++;
        }
    }

    double max_price = P * std::pow(1 + r / 100, max_level);
    std::cout << std::fixed << std::setprecision(2) << max_price << " " << count << std::endl;

    return 0;
}