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

    void clear(TreeNode* root);
    TreeNode* insert(TreeNode* root, const std::string& data);
    void traversePreOrderRec(TreeNode* root, std::vector<std::string>& res);
    void traverseInOrderRec(TreeNode* root, std::vector<std::string>& res);
    void traversePostOrderRec(TreeNode* root, std::vector<std::string>& res);
    TreeNode* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(root); }
    void insert(const std::string& data);
    std::vector<std::string> traversePreOrder();
    std::vector<std::string> traverseInOrder();
    std::vector<std::string> traversePostOrder();
};

#endif