#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> postOrderIterative(TreeNode* root) {
    std::vector<int> result;

    if (!root)
        return result;

    std::stack<TreeNode*> s1, s2;

    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty()) {
        result.push_back(s2.top()->val); // or print
        s2.pop();
    }

    return result;
}