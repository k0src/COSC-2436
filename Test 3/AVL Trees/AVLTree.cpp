#include <iostream>

class AVLTree {
private:
    struct AVLNode {
        int data;
        int height;
        AVLNode* left; AVLNode* right;
        AVLNode(int data) : data(data), height(1), left(nullptr), right(nullptr) {}
    };

    AVLNode* root;

    bool search(AVLNode* root, int target) {
        if (!root) return false;

        if (target > root->data) {
            return search(root->right, target);
        } else if (target < root->data) {
            return search(root->left, target);
        } else {
            return true;
        }
    }

public:
    bool search(int target) {
        return search(root, target);
    }
};