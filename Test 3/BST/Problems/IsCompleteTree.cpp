#include "bst.h"
#include <queue>

bool isCompleteTree(TreeNode* root) {
    if (!root) return true;

    std::queue<TreeNode*> q;

    q.push(root);

    bool found_null = false;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (!node) {
            found_null = true;
        } else {
            if (found_null) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }

    return true;
}

int main()
{

    return 0;
}