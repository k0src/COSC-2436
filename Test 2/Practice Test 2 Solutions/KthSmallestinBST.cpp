#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};


TreeNode* kthSmallestInBST(TreeNode* root, int& k) {
    if (!root) return nullptr;

    TreeNode* left = kthSmallestInBST(root->left, k);
    if (left) return left;
    
    k--;
    if (k == 0) return root;
    return kthSmallestInBST(root->right, k);
}

int main() 
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    int k = 3;

    std::cout << kthSmallestInBST(root, k)->data;

    return 0;
}