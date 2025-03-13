#include<bits/stdc++.h>

struct TreeNode{
    int val;
    int level;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) {val = x; level = 0; left = nullptr; right = nullptr;}
};

TreeNode* helper(std::vector<int>& inorder, int inStart, int inEnd, std::vector<int>& preorder, int preStart, int preEnd, std::unordered_map<int, int>& inMap){
    if(inStart > inEnd || preStart > preEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int leftSize = inRoot - inStart;
    root->left = helper(inorder, inStart, inRoot - 1, preorder, preStart + 1, preStart + leftSize, inMap);
    root->right = helper(inorder, inRoot + 1, inEnd, preorder, preStart + leftSize + 1, preEnd, inMap);
    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& preorder){
    std::unordered_map<int, int> inMap;
    for(size_t i = 0; i < preorder.size(); i++) inMap[inorder[i]] = i;
    return helper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, inMap);
}

void constructLevel(TreeNode* root, int level){
    if(!root) return;
    root->level = level;
    constructLevel(root->left, level + 1);
    constructLevel(root->right, level + 1);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::vector<int> inorder(N);
    std::vector<int> preorder(N);
    
    for(int i = 0; i < N; i++) std::cin >> inorder[i];
    for(int i = 0; i < N; i++) std::cin >> preorder[i];
    
    TreeNode* root = buildTree(inorder, preorder);

    constructLevel(root, 1);
    
    std::map<int, std::vector<int>> m;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curNode = q.front();
        m[curNode->level].push_back(curNode->val);
        q.pop();
        if(curNode->left) q.push(curNode->left);
        if(curNode->right) q.push(curNode->right);
    }

    std::vector<int> result;
    for(const auto& pair : m){
        result.push_back(pair.second.front());
    }

    for(size_t i = 0; i < result.size(); i++){
        if(i != result.size() - 1)
            std::cout << result[i] << " ";
        else
            std::cout << result[i] << std::endl;
    }
    
    return 0;
}