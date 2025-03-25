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

int maxDepth(TreeNode* root) {
    if (!root) return 0;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    std::cout << maxDepth(root);

    return 0;
}