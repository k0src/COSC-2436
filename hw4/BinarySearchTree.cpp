#include "BinarySearchTree.h"

void BinarySearchTree::clear(TreeNode* root) {
    if (!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

BinarySearchTree::TreeNode* BinarySearchTree::insert(BinarySearchTree::TreeNode* root, const std::string& data) {
    if (!root) return new TreeNode(data);

    if (data.length() > root->data.length()) {
        root->right = insert(root->right, data);
    } else if (data.length() < root->data.length()) {
        root->left = insert(root->left, data);
    } else {
        root->data = data;
    }
    
    return root;
}

void BinarySearchTree::traversePreOrderRec(BinarySearchTree::TreeNode* root, std::vector<std::string>& res) {
    if (!root) return;
    res.push_back(root->data);
    traversePreOrderRec(root->left, res);
    traversePreOrderRec(root->right, res);
}

void BinarySearchTree::traverseInOrderRec(BinarySearchTree::TreeNode* root, std::vector<std::string>& res) {
    if (!root) return;
    traverseInOrderRec(root->left, res);
    res.push_back(root->data);
    traverseInOrderRec(root->right, res);
}

void BinarySearchTree::traversePostOrderRec(BinarySearchTree::TreeNode* root, std::vector<std::string>& res) {
    if (!root) return;
    traversePostOrderRec(root->left, res);
    traversePostOrderRec(root->right, res);
    res.push_back(root->data);
}

void BinarySearchTree::insert(const std::string& data) {
    root = insert(root, data);
}

std::vector<std::string> BinarySearchTree::traversePreOrder() {
    if (!root) return {};

    std::vector<std::string> res;
    traversePreOrderRec(root, res);
    return res;
}

std::vector<std::string> BinarySearchTree::traverseInOrder() {
    if (!root) return {};

    std::vector<std::string> res;
    traverseInOrderRec(root, res);
    return res;
}

std::vector<std::string> BinarySearchTree::traversePostOrder() {
    if (!root) return {};

    std::vector<std::string> res;
    traversePostOrderRec(root, res);
    return res;
}