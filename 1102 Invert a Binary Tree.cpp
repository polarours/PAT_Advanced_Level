#include<bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){this->val = x; left = nullptr; right = nullptr;}
};

void inOrder(TreeNode* root, std::vector<int>& res) {
    if(!root) return;
    inOrder(root->right, res);
    res.push_back(root->val);
    inOrder(root->left, res);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<TreeNode*> nodes(N);
    std::vector<bool> visited(N, false);

    for(int i = 0; i < N; i++) {
        nodes[i] = new TreeNode(i);
    }

    std::string left, right;
    for(int i = 0; i < N; i++) {
        std::cin >> left >> right;
        if(left != "-") {
            nodes[i]->left = nodes[std::stoi(left)];
            visited[std::stoi(left)] = true;
        }
        if(right != "-") {
            nodes[i]->right = nodes[std::stoi(right)];
            visited[std::stoi(right)] = true;
        }
    }

    int rootIndex = 0;
    for(int i = 0; i < N; i++) {
        if(visited[i] == false) {
            rootIndex = i;
            break;
        }
    }

    TreeNode* root = nodes[rootIndex];

    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<int> levelOrder_invert, inOrder_invert;
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        levelOrder_invert.push_back(node->val);
        if(node->right != nullptr) q.push(node->right);
        if(node->left != nullptr) q.push(node->left);
    }
    inOrder(root, inOrder_invert);

    for(int i = 0; i < levelOrder_invert.size(); i++) {
        if(i != levelOrder_invert.size() - 1)
            std::cout << levelOrder_invert[i] << " ";
        else
            std::cout << levelOrder_invert[i] << std::endl;
    }

    for(int i = 0; i < inOrder_invert.size(); i++) {
        if(i != inOrder_invert.size() - 1)
            std::cout << inOrder_invert[i] << " ";
        else
            std::cout << inOrder_invert[i] << std::endl;
    }

    return 0;
}