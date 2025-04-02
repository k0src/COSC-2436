#include "help.h"

using namespace std;

// height in edges
int height(TreeNode* root) {
    if (!root) return -1;
    return std::max(height(root->left), height(root->right)) + 1;
}

// Distance from node to root in edges
int depthOfTree(TreeNode* root, TreeNode* node, int depth = 0) {
    if (!root) return -1;
    if (root == node) return depth;
    int left_depth = depthOfTree(root->left, node, depth + 1);
    if (left_depth != -1) return left_depth;
    return depthOfTree(root->right, node, depth + 1);  
}

// Search Binary Tree (BST)
bool searchBST(TreeNode* root, int target) {
    if (!root) return false;

    if (target < root->data)
        return searchBST(root->left, target);
    else if (target > root->data)
        return searchBST(root->right, target);
    return true;
}

// Search Binary Tree
bool searchBinaryTree(TreeNode* root, int target) {
    if (!root) return false;
    if (root->data == target) return true;
    return searchBinaryTree(root->left, target) || searchBinaryTree(root->right, target);
}

// Insert into Binary Tree
TreeNode* insertIntoBinaryTree(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);

    if (!root->left) {
        root->left = new TreeNode(value);
    } else if (!root->right) {
        root->right = new TreeNode(value);
    } else {
        root->left = insertIntoBinaryTree(root->left, value);
    }
    return root;
}

// Insert into  BST
TreeNode* insert(TreeNode* root, int value) {
    if (!root)
        return new TreeNode(value);
    if (value > root->data)
        root->right = insert(root->right, value);
    else if (value < root->data)
        root->left = insert(root->left, value);
    return root;
}

// Insert into binary tree level order
TreeNode* insertLevelOrder(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (!current->left) {
            current->left = new TreeNode(value);
            return root;
        }
        else if (!current->right) {
            current->right = new TreeNode(value);
            return root;
        }
        else {
            q.push(current->left);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    BinaryTree t;
    t.insert(6);
    t.insert(2);
    t.insert(3);
    t.insert(7);
    t.insert(5);
    t.insert(1);
    t.insert(9);

    t.print();

    cout << depthOfTree(t.root, t.root->left->right, 0);

    return 0;
}