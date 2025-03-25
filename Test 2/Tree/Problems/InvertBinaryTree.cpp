#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    std::swap(root->left, root->right);
    invertTree(root->right);
    invertTree(root->left);

    return root;
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printTree(root);

    TreeNode* inverted = invertTree(root);

    std::cout << std::endl;

    printTree(inverted);


    return 0;
}