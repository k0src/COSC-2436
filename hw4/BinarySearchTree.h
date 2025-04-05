#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>
#include <string>

class BinarySearchTree {
private:
    struct TreeNode {
        std::string data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(const std::string& data) : data(data), left(nullptr), right(nullptr) {}
    };

    void clear(TreeNode* root) {
        if (!root) return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

    TreeNode* insert(TreeNode* root, const std::string& data) {
        if (!root) return new TreeNode(data);

        if (data.length() > root->data.length()) {
            root->right = insert(root->right, data);
        } else {
            root->left = insert(root->left, data);
        }
        return root;
    }

    void traversePreOrderRec(TreeNode* root, std::vector<std::string>& res) {
        if (!root) return;
        res.push_back(root->data);
        traversePreOrderRec(root->left, res);
        traversePreOrderRec(root->right, res);
    }

    void traverseInOrderRec(TreeNode* root, std::vector<std::string>& res) {
        if (!root) return;
        traverseInOrderRec(root->left, res);
        res.push_back(root->data);
        traverseInOrderRec(root->right, res);
    }

    void traversePostOrderRec(TreeNode* root, std::vector<std::string>& res) {
        if (!root) return;
        traversePostOrderRec(root->left, res);
        traversePostOrderRec(root->right, res);
        res.push_back(root->data);
    }

    TreeNode* root;
public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() { clear(root); }

    void insert(const std::string& data) {
        root = insert(root, data);
    }

    std::vector<std::string> traversePreOrder() {
        if (!root) throw std::runtime_error("Tree is empty");

        std::vector<std::string> res;
        traversePreOrderRec(root, res);
        return res;
    }

    std::vector<std::string> traverseInOrder() {
        if (!root) throw std::runtime_error("Tree is empty");

        std::vector<std::string> res;
        traverseInOrderRec(root, res);
        return res;
    }

    std::vector<std::string> traversePostOrder() {
        if (!root) throw std::runtime_error("Tree is empty");
        
        std::vector<std::string> res;
        traversePostOrderRec(root, res);
        return res;
    }
};

#endif