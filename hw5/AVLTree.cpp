#include "AVLTree.h"

void AVLTree::clear(AVLTree::node* root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

int AVLTree::getNodeHeight(AVLTree::node* root) {
    if (!root) return 0;
    return root->height;
}

int AVLTree::getBalanceFactor(AVLTree::node* root) {
    if (!root) return 0;
    return getNodeHeight(root->left) - getNodeHeight(root->right);
}

AVLTree::node* AVLTree::getMinNode(AVLTree::node* root) {
    node* current = root;

    while (current && current->left) {
        current = current->left;
    }
    return current;
}

AVLTree::node* AVLTree::rotateLeft(AVLTree::node* root) {
    node* new_root = root->right;

    root->right = new_root->left;
    new_root->left = root;

    root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    new_root->height = std::max(getNodeHeight(new_root->left), getNodeHeight(new_root->right)) + 1;

    return new_root;
}

AVLTree::node* AVLTree::rotateRight(AVLTree::node* root) {
    node* new_root = root->left;

    root->left = new_root->right;
    new_root->right = root;

    root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    new_root->height = std::max(getNodeHeight(new_root->left), getNodeHeight(new_root->right)) + 1;

    return new_root;
}

AVLTree::node* AVLTree::balance(AVLTree::node* root) {
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

AVLTree::node* AVLTree::insert(AVLTree::node* root, int data) {
    if (!root) return new node(data);

    if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        return root;
    }

    root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;

    return balance(root);
}

AVLTree::node* AVLTree::remove(AVLTree::node* root, int data) {
    if (!root) return nullptr;

    if (data > root->data) {
        root->right = remove(root->right, data);
    } else if (data < root->data) {
        root->left = remove(root->left, data);
    } else {
        if (!root->left) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            node* temp = root->left;
            delete root;
            return temp;
        } else {
            node* min_node = getMinNode(root->right);
            root->data = min_node->data;
            root->right = remove(root->right, min_node->data);
        }
    }
    root->height = std::max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    return balance(root);
}

std::vector<int> AVLTree::levelOrder(AVLTree::node* root) {
    if (!root) return {};

    std::vector<int> level_order;
    std::queue<AVLTree::node*> q;

    q.push(root);

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            AVLTree::node* current = q.front();
            q.pop();
            level_order.push_back(current->data);

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        level_order.push_back(-1);
    }
    return level_order;
}

void AVLTree::insert(int data) {
    root = insert(root, data);
}

void AVLTree::remove(int data) {
    root = remove(root, data);
}

std::vector<int> AVLTree::levelOrder() {
    return levelOrder(root);
}