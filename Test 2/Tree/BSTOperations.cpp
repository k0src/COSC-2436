#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

bool search(TreeNode* root, int target) {
    if (!root)
        return false;

    if (target > root->value)
        return search(root->right, target);
    else if (target < root->value)
        return search(root->left, target);
    else
        return true;
}

TreeNode* insert(TreeNode* root, int value) {
    if (!root)
        return new TreeNode(value);
    if (value > root->value)
        root->right = insert(root->right, value);
    else if (value < root->value)
        root->left = insert(root->left, value);
    return root;
}

TreeNode* minValueNodeRec(TreeNode* root) {
    if (!root->left) return root;
    return minValueNodeRec(root->left);
}

TreeNode* minValueNode(TreeNode* root) {
    TreeNode* current = root;
    
    while (current && current->left)
        current = current->left;
    return current;
}

TreeNode* remove(TreeNode* root, int value) {
    if (!root)
        return nullptr;

    // Traverse tree to find target value
    if (value > root->value)
        root->right = remove(root->right, value);
    else if (value < root->value)
        root->left = remove(root->left, value);
    else {
        // Check if left child is missing
        if (!root->left) {
            // Delete node, return right child
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            // Delete node, return left child
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            // Find min node in right subtree, set current node's value to the min value,
            // remove the min node
            TreeNode* minNode = minValueNode(root->right);
            root->value = minNode->value;
            root->right = remove(root->right, minNode->value);
        }
    }
    return root;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);
    insert(root, 21);

    int target = 3;

    remove(root, 3);

    std::cout << search(root, target) << std::endl;
    std::cout << minValueNode(root)->value;

    return 0;
}