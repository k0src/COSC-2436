#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return nullptr;

    if (root->val == val) return root;
    else if (root->val < val) return searchBST(root->right, val); 
    else return searchBST(root->left, val);
    return root;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (root->val < val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;

    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() 
{
    TreeNode* root;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);

    TreeNode* res = searchBST(root, 2);
    printTree(root);
    std::cout << std::endl;
    printTree(res);

    return 0;
}