#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getDepth(TreeNode* root, TreeNode* node, int depth = 0) {
    if (!root) return -1;
    if (root == node) return depth;

    int left = getDepth(root->left, node, depth + 1);
    if (left != -1) return left;

    return getDepth(root->right, node, depth + 1);
}

TreeNode* getParent(TreeNode* root, TreeNode* node, TreeNode* parent = nullptr) {
    if (!root) return nullptr;
    if (root == node) return parent;

    TreeNode* left = getParent(root->left, node, root);
    if (left) return left;

    return getParent(root->right, node, root);
}

void printCousinsHelper(TreeNode* root, TreeNode* target, int depth, TreeNode* parent, TreeNode* targetParent) {
    if (!root || depth < 0) return;

    if (depth == 0 && parent != targetParent && root != target) {
        std::cout << root->val << " ";
        return;
    }

    printCousinsHelper(root->left, target, depth - 1, root, targetParent);
    printCousinsHelper(root->right, target, depth - 1, root, targetParent);
}

void printCousins(TreeNode* root, TreeNode* node) {
    if (!root || !node || root == node) return;

    int depth = getDepth(root, node);
    TreeNode* parent = getParent(root, node);

    printCousinsHelper(root, node, depth, nullptr, parent);
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

    printCousins(root, root->left->left);

    return 0;
}