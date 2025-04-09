#include <iostream>

class AVLTree {
private:
    struct AVLNode {
        int data;
        int height;
        AVLNode* left; AVLNode* right;
        AVLNode(int data) : data(data), height(1), left(nullptr), right(nullptr) {}
    };

    AVLNode* root;

    void clear(AVLNode* root) {
        if (root) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }

    int getNodeHeight(AVLNode* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (!node) return 0;
        return getNodeHeight(node->left) - getNodeHeight(node->right);
    }

    AVLNode* rotateLeft(AVLNode* root) {
        AVLNode* new_root = root->right;

        root->right = new_root->left;
        new_root->left = root;

        root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
        new_root->height = std::max(getNodeHeight(new_root->left), getNodeHeight(new_root->right)) + 1;

        return new_root;
    }

    AVLNode* rotateRight(AVLNode* root) {
        AVLNode* new_root = root->left;

        root->left = new_root->right;
        new_root->right = root;

        root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
        new_root->height = std::max(getNodeHeight(new_root->left), getNodeHeight(new_root->right)) + 1;

        return new_root;
    }

    AVLNode* balance(AVLNode* root) {
        int balance_factor = getBalanceFactor(root);

        if (balance_factor > 1) {
            if (getBalanceFactor(root->left) < 0) {
                root->left = rotateLeft(root->left);
            }
            return rotateRight(root);
        } else if (balance_factor < -1) {
            if (getBalanceFactor(root->right) > 0) {
                root->right = rotateRight(root->right);
            }
            return rotateLeft(root);
        }

        return root;
    }
    
    AVLNode* insert(AVLNode* root, int data) {
        if (!root) {
            return new AVLNode(data);
        }

        if (data > root->data) {
            root->right = insert(root->right, data);
        } else if (data < root->data) {
            root->left = insert(root->left, data);
        }

        root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;

        return balance(root);
    }

    AVLNode* getMinNode(AVLNode* root) {
        AVLNode* current = root;

        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    AVLNode* remove(AVLNode* root, int data) {
        if (!root) {
            return nullptr;
        }

        if (data > root->data) {
            root->right = remove(root->right, data);
        } else if (data < root->data) {
            root->left = remove(root->left, data);
        } else {
            if (!root->left) {
                AVLNode* temp = root->right;
                delete root;
                root = nullptr;
                return temp;
            } else if (!root->right) {
                AVLNode* temp = root->left;
                delete root;
                root = nullptr;
                return temp;
            } else {
                AVLNode* min_node = getMinNode(root->right);
                root->data = min_node->data;
                root->right = remove(root->right, min_node->data);
            }
        }

        root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;

        return balance(root);
    }

    bool search(AVLNode* root, int target) {
        if (!root) return false;

        if (target > root->data) {
            return search(root->right, target);
        } else if (target < root->data) {
            return search(root->left, target);
        } else {
            return true;
        }
    }

public:
    AVLTree() : root(nullptr) {}
        
    ~AVLTree() {
        clear(root);
    }

    bool search(int target) {
        return search(root, target);
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void remove(int data) {
        root = remove(root, data);
    }
};

int main()
{
    AVLTree t;
    t.insert(1);
    t.insert(3);
    t.insert(5);
    t.insert(6);
    t.remove(1);
    return 0;
}