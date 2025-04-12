#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left; TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->data;
    }
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << sumOfLeftLeaves(root) << std::endl;

    return 0;
}