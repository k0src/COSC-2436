#include "bst.h"

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p || root == q) return root;

    if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    } else if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
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