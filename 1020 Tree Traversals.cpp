#include<bits/stdc++.h>

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* TreeBuilder(const std::vector<int>& inorder, const std::vector<int>& postorder, int inorder_start, int inorder_end, int postorder_start, int postorder_end, std::unordered_map<int, int> inorder_map){
  if(inorder_start > inorder_end || postorder_start > postorder_end){
    return nullptr;
  }

  int root_val = postorder[postorder_end];
  TreeNode* root = new TreeNode(root_val);

  //在中序遍历中查找根节点的位置
  int root_index = inorder_map[root_val];
  //左子树节点数量
  int left_size = root_index - inorder_start;

  root->left = TreeBuilder(inorder, postorder, inorder_start, root_index - 1, postorder_start, postorder_start + left_size - 1, inorder_map);
  root->right = TreeBuilder(inorder, postorder, root_index + 1, inorder_end, postorder_start + left_size, postorder_end - 1, inorder_map);

  return root;
}

int main(){
  int N, val;
  std::cin >> N;

  std::vector<int> inorder(N), postorder(N);
  std::unordered_map<int, int> inorder_map;

  for(int i = 0; i < N; i++){
    std::cin >> val;
    postorder[i] = val;
  }

  for(int i = 0; i < N; i++){
    std::cin >> val;
    inorder[i] = val;
    inorder_map[val] = i;
  }

  TreeNode* t = TreeBuilder(inorder, postorder, 0, N - 1, 0, N - 1, inorder_map);

  std::vector<int> result;
  std::queue<TreeNode*> q;
  q.push(t);
  while(!q.empty()){
    TreeNode* cur = q.front();
    q.pop();
    result.push_back(cur->val);
    if(cur->left != nullptr) q.push(cur->left);
    if(cur->right != nullptr) q.push(cur->right);
  }

  for(int i = 0; i < result.size(); i++){
    if(i != result.size() - 1)
      std::cout << result[i] << " ";
    else
      std::cout << result[i] << std::endl;
  }

  return 0;
}
