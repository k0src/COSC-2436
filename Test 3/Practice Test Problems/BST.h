#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;
public:
    BST() : root(nullptr) {}
    
    TreeNode* insert(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);

        if (value > node->data) {
            node->right = insert(node->right, value);
        } else if (value < node->data) {
            node->left = insert(node->left, value);
        }
        return node;
    }

    int minValue(TreeNode* node) {
        if (!node || !node->left) {
            return node->data;
        }

        return minValue(node->left);
    }

    TreeNode* remove(TreeNode* node, int value) {
        if (!node) return nullptr;

        if (value > node->data) {
            node->right = remove(node->right, value);
        } else if (value < node->data) {
            node->left = remove(node->left, value);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                int min_value = minValue(node->right);
                node->data = min_value;
                node->right = remove(node->right, min_value);
            }
        }
        return node;
    }

    bool search(TreeNode* node, int value) {
        if (!node) return false;

        if (value > node->data) {
            return search(node->right, value);
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return true;
        }
    }

    void printInorder(TreeNode* node) {
        if (!node) return;

        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

    void printPreorder(TreeNode* node) {
        if (!node) return;

        std::cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void printPostorder(TreeNode* node) {
        if (!node) return;

        printPostorder(node->left);
        printPostorder(node->right);
        std::cout << node->data << " ";
    }
public:
    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void printInorder() {
        printInorder(root);
    }

    void printPreorder() {
        printPreorder(root);
    }

    void printPostorder() {
        printPostorder(root);
    }

    void printLevelOrder() {
        if (!root) return;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            std::cout << front->data << " ";

            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }

    TreeNode* getRoot() {
        return root;
    }
};