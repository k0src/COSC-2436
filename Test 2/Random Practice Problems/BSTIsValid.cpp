#include <iostream>

using namespace std;

struct TreeNode{int val; TreeNode* left; TreeNode* right;};

bool isValidBST(TreeNode* root) {
    return valid(root, LONG_MIN, LONG_MAX);        
}

bool valid(TreeNode* node, long minimum, long maximum) {
    if (!node) return true;

    if (!(node->val > minimum && node->val < maximum)) return false;

    return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
}