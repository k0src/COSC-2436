#include "bst.h"
#include <cmath>

int getHeight(TreeNode* node) {
    if (!node) return -1;

    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    
    return isBalanced(root->left) && isBalanced(root->right) && (abs(getHeight(root->left) - getHeight(root->right)) <= 1);
}

int main()
{
    BST t;
    t.insert(5);
    t.insert(6);
    t.insert(4);

    std::cout << isBalanced(t.root); 

    return 0;
}