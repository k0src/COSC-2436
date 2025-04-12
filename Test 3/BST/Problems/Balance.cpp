#include <iostream>
#include <algorithm>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBalancedBST(const std::vector<int>& nodes, int left, int right) {
    if (left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);
    
    root->left = buildBalancedBST(nodes, left, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, right);
    
    return root;
}

void inorder(TreeNode* root, std::vector<int>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

TreeNode* balanceBST(TreeNode* root) {
    std::vector<int> nodes;
    inorder(root, nodes);
    return buildBalancedBST(nodes, 0, nodes.size() - 1);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);

    TreeNode* balanced1 = balanceBST(root);
    TreeNode* balanced2 = balanceBST(root2);

    printInorder(balanced1);
    std::cout << std::endl;

    printInorder(balanced2);
    std::cout << std::endl;

    return 0;
}