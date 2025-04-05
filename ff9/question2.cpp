#include <iostream>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode* root) {
    if (!root) return;

    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (root->val < val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return root;
}

bool findTargetRec(TreeNode* root, int k, std::unordered_set<int>& set) {
    if (!root) return false;

    int diff = k - root->val;
    if (set.count(diff)) return true;
    else set.insert(root->val);
    return findTargetRec(root->left, k, set) || findTargetRec(root->right, k, set);
}

bool findTarget(TreeNode* root, int k) {
    if (!root) return false;

    std::unordered_set<int> set;
    return findTargetRec(root, k, set);
}

int main()
{
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    printTree(root);
    std::cout << std::endl
              << findTarget(root, 9) << std::endl
              << findTarget(root, 28) << std::endl;
    
    return 0;
}