#include <bits/stdc++.h>

struct TreeNode {
    int val;
    int level;
    std::vector<int> children;
    TreeNode(int x) : val(x), level(1) {}
};

std::vector<TreeNode*> nodes(200, nullptr);

void constructLevel(TreeNode* root, int level) {
    if(!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        for(int i = 0; i < node->children.size(); i++) {
            if(nodes[node->children[i]] != nullptr) {
                nodes[node->children[i]]->level = node->level + 1;
                q.push(nodes[node->children[i]]);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::cin.ignore();

    int ID, K, Child;
    TreeNode* root;

    while(M--) {
        std::cin >> ID >> K;
        if(ID == 1) {
            root = new TreeNode(ID);
            for(int i = 0; i < K; i++) {
                std::cin >> Child;
                root->children.push_back(Child);
                if(nodes[Child] == nullptr) {
                    nodes[Child] = new TreeNode(Child);
                }
            }
            nodes[ID] = root;
        }else {
            TreeNode* Node;
            if(nodes[ID] != nullptr) {
                Node = nodes[ID];
            }else {
                Node = new TreeNode(ID);
            }
            for(int i = 0; i < K; i++) {
                std::cin >> Child;
                Node->children.push_back(Child);
                if(nodes[Child] == nullptr)
                    nodes[Child] = new TreeNode(Child);
            }
            nodes[ID] = Node;
        }
    }

    constructLevel(root, 1);
    int maxLevel = INT_MIN, maxNum = INT_MIN;
    std::queue<TreeNode*> q;
    q.push(root);
    std::map<int, int> m;
    while(!q.empty()) {
        TreeNode* Node = q.front();
        q.pop();
        int curLevel = Node->level;
        if(m.find(curLevel) == m.end()) {
            m[curLevel] = 1;
        }else {
            m[curLevel] += 1;
        }
        for(int child : Node->children) {
            q.push(nodes[child]);
        }
    }

    for(const auto& pair : m) {
        if(pair.second > maxNum) {
            maxNum = pair.second;
            maxLevel = pair.first;
        }
    }

    std::cout << maxNum << " " << maxLevel << std::endl;

    return 0;
}