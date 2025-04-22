#include <iostream>
#include "BST.h"
#include <stack>
#include <queue>

using namespace std;

// BST

int bstGetMinIter(TreeNode* root) {
    if (!root) return -1;

    while (root->left) {
        root = root->left;
    }

    return root->data;
}

int bstGetMaxIter(TreeNode* root) {
    if (!root) return -1;

    while (root->right) {
        root = root->right;
    }

    return root->data;
}

int bstGetMinRec(TreeNode* root) {
    if (!root || !root->left) {
        return root->data;
    }

    return bstGetMinRec(root->left);
}

int bstGetMaxRec(TreeNode* root) {
    if (!root || !root->right) {
        return root->data;
    }

    return bstGetMaxRec(root->right);
}

// BINARY TREE

int binaryTreeGetMinRec(TreeNode* root) {
    if (!root) return -1;

    int min_value = root->data;
    if (root->left) {
        min_value = min(min_value, binaryTreeGetMinRec(root->left));
    }
    if (root->right) {
        min_value = min(min_value, binaryTreeGetMinRec(root->right));
    }

    return min_value;
}

int binaryTreeGetMaxRec(TreeNode* root) {
    if (!root) return -1;

    int max_value = root->data;
    if (root->left) {
        max_value = max(max_value, binaryTreeGetMaxRec(root->left));
    }
    if (root->right) {
        max_value = max(max_value, binaryTreeGetMaxRec(root->right));
    }

    return max_value;
}

int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(17);

    cout << binaryTreeGetMinRec(bst.getRoot()) << endl;
    cout << binaryTreeGetMaxRec(bst.getRoot()) << endl;

    return 0;
}