#include <bits/stdc++.h>

struct TreeNode{
    int val;
    int level;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){this->val = x; this->level = 0; 
    this->left = nullptr; this->right = nullptr;}
};

bool isCompleteTree(TreeNode* root, int& lastNode){
    if(root == nullptr) return true;
    bool end = false;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curNode = q.front();
        q.pop();
        if(end){
            if(curNode) return false;
        }else{
            if(!curNode) end = true;
            else {
                lastNode = curNode->val;
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
    }

    return true;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<bool> visited(N, false);
    std::vector<TreeNode*> nodes(N, nullptr);
    for(int i = 0; i < N; i++){
        nodes[i] = new TreeNode(i);
    }
    int leftIndex, rightIndex, rootIndex;
    std::string left, right;
    for(int i = 0; i < N; i++){
        std::cin >> left >> right;
        if(left != "-") {
            leftIndex = std::stoi(left);
            nodes[i]->left = nodes[leftIndex];
            visited[leftIndex] = true;
        }
        if(right != "-") {
            rightIndex = std::stoi(right);
            nodes[i]->right = nodes[rightIndex];
            visited[rightIndex] = true;
        }
    }

    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            rootIndex = i;
            break;
        }
    }

    TreeNode* root = nodes[rootIndex];
    int lastNode = 0;
    bool isComplete = isCompleteTree(root, lastNode);
    if(isComplete){
        std::cout << "YES " << lastNode << std::endl;
    }else{
        std::cout << "NO " << rootIndex << std::endl;
    }

    return 0;
}