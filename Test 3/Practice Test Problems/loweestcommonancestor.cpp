#include "bst.h"

using namespace std;

TreeNode* getParent(TreeNode* root, TreeNode* node, TreeNode* parent = nullptr) {
    if (!root) return nullptr;
    if (root == node) return parent;

    TreeNode* left = getParent(root->left, node, root);
    if (left) return left;

    return getParent(root->right, node, root);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    if (left) return left;
    if (right) return right;
    return nullptr;
}

int main()
{
    BST bst;
    bst.insert(6);
    bst.insert(2);
    bst.insert(8);
    bst.insert(0);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);
    bst.insert(3);
    bst.insert(5);

    cout << lowestCommonAncestor(bst.getRoot(), bst.getRoot()->left, bst.getRoot()->right)->data;

    return 0;
}