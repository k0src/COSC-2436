#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left; TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

int getDepth(TreeNode* root, int val, int depth = 0) {
    if (!root) return -1;
    if (root->data == val) return depth;
    int leftDepth = getDepth(root->left, val, depth + 1);
    if (leftDepth != -1) return leftDepth;
    return getDepth(root->right, val, depth + 1);
}

TreeNode* getParent(TreeNode* root, int val, TreeNode* parent = nullptr) {
    if (!root) return nullptr;
    if (root->data == val) return parent;
    TreeNode* left = getParent(root->left, val, root);
    if (left) return left;
    return getParent(root->right, val, root);
}

bool isCousins(TreeNode* root, int x, int y) {
    if (!root) return false;
    return getDepth(root, x) == getDepth(root, y) && getParent(root, x) != getParent(root, y);
}

int main()
{
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    std::cout << "Test case 1: " << (isCousins(root1, 4, 3) ? "true" : "false") << std::endl;

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    std::cout << "Test case 2: " << (isCousins(root2, 5, 4) ? "true" : "false") << std::endl;

    return 0;
}