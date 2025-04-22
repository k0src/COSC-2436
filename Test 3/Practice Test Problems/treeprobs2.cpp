#include "bst.h"

using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;

    return (p->data == q->data) &&
           isSameTree(p->right, q->left) &&
           isSameTree(p->left, q->right);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSameTree(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << isSymmetric(root) << endl;
    return 0;
}