#include <iostream>
#include <queue>

class BST {
private:
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        int data;
        TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    TreeNode* _root;

    bool search(TreeNode* root, int item) {
        if (!root) return false;

        if (item > root->data) {
            return search(root->right, item);
        } else if (item < root->data) {
            return search(root->left, item);
        } else {
            return true;
        }
    }

    TreeNode* insert(TreeNode* root, int item) {
        if (!root) return new TreeNode(item);

        if (item > root->data) {
            root->right = insert(root->right, item);
        } else if (item < root->data) {
            root->left = insert(root->left, item);
        }

        return root;
    }

    int getMinValue(TreeNode* root) {
        if (!root || !root->left) {
            return root->data;
        }

        return getMinValue(root->left);
    }

    TreeNode* remove(TreeNode* root, int item) {
        if (!root) return nullptr;

        if (item > root->data) {
            root->right = remove(root->right, item);
        } else if (item < root->data) {
            root->left = remove(root->left, item);
        } else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                int min_value = getMinValue(root->right);
                root->data = min_value;
                root->right = remove(root->right, min_value);
            }
        }
        return root;
    }

    void printInorder(TreeNode* root) {
        if (!root) return;

        printInorder(root->left);
        std::cout << root->data << " ";
        printInorder(root->right);
    }

    void printPreorder(TreeNode* root) {
        if (!root) return;

        std::cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

    void printPostorder(TreeNode* root) {
        if (!root) return;

        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << root->data << " ";
    }

public:
    void insert(int item) {
        _root = insert(_root, item);
    }

    void remove(int item) {
        _root = remove(_root, item);
    }

    bool search(int item) {
        return search(_root, item);
    }

    void printInorder() {
        printInorder(_root);
    }

    void printPreorder() {
        printPreorder(_root);
    }

    void printPostorder() {
        printPostorder(_root);
    }

    void printLevelOrder() {
        if (!_root) return;

        std::queue<TreeNode*> q;
        q.push(_root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            std::cout << node->data << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};

int main() 
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    bst.printInorder();
    std::cout << std::endl;
    bst.printPreorder();
    std::cout << std::endl;
    bst.printPostorder();
    std::cout << std::endl;
    bst.printLevelOrder();
    std::cout << std::endl;

    bst.remove(10);
    bst.printInorder();
    std::cout << std::endl;

    std::cout << bst.search(10) << std::endl;
    std::cout << bst.search(5) << std::endl;

    return 0;
}