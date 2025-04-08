#include "bst.h"

TreeNode* getInorderPredecessor(TreeNode* node) {
    if (!node || !node->left) return node;

    node = node->left;

    while (node->right) {
        node = node->right;
    }

    return node;
}

TreeNode* getInorderSuccessor(TreeNode* node) {
    if (!node || !node->right) return node;

    node = node->right;

    while (node->left) {
        node = node->left;
    }

    return node;
}

int main()
{
    BST t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    t.insert(2);
    t.insert(4);
    t.insert(6);

    std::cout << getInorderPredecessor(t.root)->data << std::endl; // 4
    std::cout << getInorderSuccessor(t.root)->data << std::endl; // 6
}