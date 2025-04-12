#include <iostream>

struct Node {
    int t;
    int* keys;
    int n; // Current number of keys
    Node** children; // Child pointers
    bool leaf;

    Node(int t, bool leaf) : t(t), n(0), leaf(leaf) {
        keys = new int[2 * t - 1];
        children = new Node*[2 * t];
    }
};

Node* BTreeSearch(Node* root, int target) {
    int i = 0;

    while (i < root->n && target > root->keys[i]) {
        i++;
    }

    if (i < root->n && target == root->keys[i]) {
        return root;
    }

    if (root->leaf) {
        return nullptr;
    }

    return BTreeSearch(root->children[i], target);
}

void BTreeTraverse(Node* root) {
    if (root == nullptr) return;

    int i;
    for (i = 0; i < root->n; i++) {
        // Traverse the left child before printing key[i]
        if (!root->leaf) {
            BTreeTraverse(root->children[i]);
        }
        std::cout << root->keys[i] << " ";
    }

    // Traverse the rightmost child
    if (!root->leaf) {
        BTreeTraverse(root->children[i]);
    }
}


int main()
{

    return 0;
}