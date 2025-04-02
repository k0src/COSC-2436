#include <iostream>
#include <iomanip>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);

    if (!root->left) {
        root->left = new TreeNode(value);
        return root;
    }

    if (!root->right) {
        root->right = new TreeNode(value);
        return root;
    }

    if (insert(root->left, value)) return root;
    if (insert(root->right, value)) return root;

    return root; // Should never reach here
}

bool search(TreeNode* root, int target) {
    if (!root) return false;

    if (root->value == target) return true;
    return search(root->left, target) || search(root->right, target);
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    std::cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printElementsLessThanK(TreeNode* root, int k) {
    if (!root) return;

    if (root->value < k) std::cout << root->value << " ";
    printElementsLessThanK(root->left, k);
    printElementsLessThanK(root->right, k);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    
    insert(root, 3);
    insert(root, 2);
    insert(root, 7);
    insert(root, 9);
    insert(root, 4);
    insert(root, 11);

    printPreorder(root);

    std::cout << std::boolalpha << std::endl << search(root, 2) 
              << std::endl << search(root, 10) << std::endl; // true, false
    
    printElementsLessThanK(root, 5); // 1 2 3 4

    return 0;
}