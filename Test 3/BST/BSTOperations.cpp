#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

bool search(TreeNode* root, int target) {
    if (!root)
        return false;

    if (target > root->data)
        return search(root->right, target);
    else if (target < root->data)
        return search(root->left, target);
    else
        return true;
}

TreeNode* insert(TreeNode* root, int data) {
    if (!root) return new TreeNode(data);

    if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}

int minValue(TreeNode* root) {
    if (!root || !root->left) 
        return root->data;
    
    return minValue(root->left);
}

int maxValue(TreeNode* root) {
    if (!root || !root->right) 
        return root->data;
    
    return maxValue(root->right);
}

TreeNode* minValueNode(TreeNode* root) {
    TreeNode* current = root;
    
    while (current && current->left)
        current = current->left;
    return current;
}

TreeNode* remove(TreeNode* root, int target) {
    if (!root)
        return nullptr;

    if (target > root->data)
        root->right = remove(root->right, target);
    else if (target < root->data)
        root->left = remove(root->left, target);
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            int min_value = minValue(root->right);
            root->data = min_value;
            root->right = remove(root->right, min_value);
        }
    }
    return root;
}

int height(TreeNode* root) {
    if (!root)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

int getNodeDepth(TreeNode* root, TreeNode* node, int depth = 0) {
    if (!root)
        return -1;
    if (root == node)
        return depth;
    int leftDepth = getNodeDepth(root->left, node, depth + 1);
    if (leftDepth != -1)
        return leftDepth;
    return getNodeDepth(root->right, node, depth + 1);
}

int main()
{
    return 0;
}