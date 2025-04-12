#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int convertToSumTree(TreeNode* root) {
    if (!root) return 0;

    int leftSum = convertToSumTree(root->left);
    int rightSum = convertToSumTree(root->right);

    int oldVal = root->val;
    root->val = leftSum + rightSum;

    return oldVal + root->val;
}

TreeNode* sumTree(TreeNode* root) {
    convertToSumTree(root);
    return root;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    TreeNode* sumRoot = sumTree(root);

    printInorder(sumRoot);

    return 0;
}