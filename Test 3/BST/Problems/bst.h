#ifndef BST_H
#define BST_H

#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    void insert(TreeNode*& node, int value) {
        if (!node) {
            node = new TreeNode(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        }
    }

    void printInOrder(TreeNode* node) const {
        if (node) {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void clear(TreeNode* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(int value) {
        insert(root, value);
    }

    void printInOrder() const {
        printInOrder(root);
        std::cout << std::endl;
    }
};

#endif