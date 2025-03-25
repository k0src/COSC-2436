#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode* root) {
    if (!root) return;

    std::cout << root->value << " ";
    printTree(root->left);
    printTree(root->right);
}

int dfs(TreeNode* root, int& res) {
    if (!root) {
        return 0;
    }
    int left = dfs(root->left, res);
    int right = dfs(root->right, res);
    res = std::max(res, left + right);
    return 1 + std::max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
}

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(5);

    std::cout << diameterOfBinaryTree(root);

    return 0;
}