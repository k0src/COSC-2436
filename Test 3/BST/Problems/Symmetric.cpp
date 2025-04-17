#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left; TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool dfs(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;

    return left->val == right->val &&
           dfs(left->left, right->right) &&
           dfs(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return dfs(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    std::cout << isSymmetric(root);

    return 0;
}