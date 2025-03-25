#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    
    
}

void printTree(TreeNode* root) {
    if (!root) return;

    std::cout << root->value << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(4);
    root2->right->left->left = new TreeNode(5);
    
    std::cout << isBalanced(root) << std::endl;
    std::cout << isBalanced(root2) << std::endl;

    return 0;
}