#include "help.h"

using namespace std;

class AVLTree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;
        int height;
        Node(int val) : val(val), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    bool search(Node* node, int val) {
        if (!node) return false;

        if (val > node->val) {
            return search(node->right, val);
        } else if (val < node->val) {
            return search(node->left, val);
        }

        return true;
    }

    int getHeight(Node* node) {
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateLeft(Node* node) {
        Node* new_root = node->right;

        node->right = new_root->left;
        new_root->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

        return new_root;
    }

    Node* rotateRight(Node* node) {
        Node* new_root = node->left;

        node->right = new_root->right;
        new_root->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

        return new_root;
    }

    Node* balance(Node* node) {
        int bf = getBalanceFactor(node);

        if (bf > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        } else if (bf < -1) {
            if (getBalanceFactor(node) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val > node->val) {
            node->right = insert(node->right, val);
        } else if (val < node->val) {
            node->left = insert(node->left, val);
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        return balance(node);
    }

    int getMinValue(Node* node) {
        if (!node || !node->left) {
            return node->val;
        }

        return getMinValue(node->left);
    }

    Node* remove(Node* node, int val) {
        if (!node) return nullptr;

        if (val > node->val) {
            node->right = remove(node->right, val);
        } else if (val < node->val) {
            node->left = remove(node->left, val);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                int min_value = getMinValue(node->right);
                node->val = min_value;
                node->right = remove(node->right, min_value);
            }
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        return balance(node);
    }
public:
    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }
};