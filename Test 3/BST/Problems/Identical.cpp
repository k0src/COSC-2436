#include "bst.h"

bool identical(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;

    return (t1->data == t2->data) && identical(t1->left, t2->left) && identical(t1->right, t2->right);
}

int main()
{
    BST t1, t2;
    t1.insert(1);
    t1.insert(2);
    t1.insert(3);

    t2.insert(1);
    t2.insert(2);
    t2.insert(3);

    std::cout << identical(t1.root, t2.root);
}