#include <iostream>

class BTree {
private:
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

    void splitChild(Node* x, int i, Node* y) {
        Node* z = new Node(y->t, y->leaf);
        z->n = t - 1;
    
        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t]; 
        }
    
        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }
    
        y->n = t - 1;
    
        for (int j = x->n; j >= i + 1; j--) {
            x->children[j + 1] = x->children[j];
        }
    
        x->children[i + 1] = z;
    
        for (int j = x->n - 1; j >= i; j--) {
            x->keys[j + 1] = x->keys[j];
        }
    
        x->keys[i] = y->keys[t - 1];
    
        x->n += 1;
    }

    void insertNonFull(Node* x, int k) {
        int i = x->n - 1;
    
        if (x->leaf) {
            while (i >= 0 && k < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = k;
            x->n += 1;
        } else {
            while (i >= 0 && k < x->keys[i])
                i--;
    
            i++;
    
            if (x->children[i]->n == 2 * t - 1) {
                splitChild(x, i, x->children[i]);
    
                if (k > x->keys[i])
                    i++;
            }
            insertNonFull(x->children[i], k);
        }
    }

    int findKey(Node* node, int k) {
        int i = 0;
        while (i < node->n && node->keys[i] < k) {
            ++i;
        }
        return i;
    }

    int getPredecessor(Node* node, int i) {
        Node* current = node->children[i];
        while (!current->leaf) {
            current = current->children[current->n];
        }
        return current->keys[current->n - 1];
    }

    int getSuccessor(Node* node, int i) {
        Node* current = node->children[i + 1];
        while (!current->leaf) {
            current = current->children[0];
        }
        return current->keys[0];
    }

    void merge(Node* node, int i) {
        Node* child = node->children[i];
        Node* sibling = node->children[i + 1];

        child->keys[t - 1] = node->keys[i];

        for (int j = 0; j < sibling->n; j++) {
            child->keys[j + t] = sibling->keys[j];
        }

        if (!child->leaf) {
            for (int j = 0; j <= sibling->n; j++) {
                child->children[j + t] = sibling->children[j];
            }
        }

        for (int j = i + 1; j < node->n; j++) {
            node->keys[j - 1] = node->keys[j];
        }

        for (int j = i + 2; j <= node->n; j++) {
            node->children[j - 1] = node->children[j];
        }

        child->n += sibling->n + 1;
        node->n--;
        delete sibling;
    }

    void borrowFromPrev(Node* node, int i) {
        Node* child = node->children[i];
        Node* sibling = node->children[i - 1];

        for (int j = child->n - 1; j >= 0; j--) {
            child->keys[j + 1] = child->keys[j];
        }

        if (!child->leaf) {
            for (int j = child->n; j >= 0; j--) {
                child->children[j + 1] = child->children[j];
            }
        }

        child->keys[0] = node->keys[i - 1];

        if (!child->leaf) {
            child->children[0] = sibling->children[sibling->n];
        }

        node->keys[i - 1] = sibling->keys[sibling->n - 1];

        child->n += 1;
        sibling->n -= 1;
    }

    void borrowFromNext(Node* node, int i) {
        Node* child = node->children[i];
        Node* sibling = node->children[i + 1];

        child->keys[child->n] = node->keys[i];

        if (!child->leaf) {
            child->children[child->n + 1] = sibling->children[0];
        }

        node->keys[i] = sibling->keys[0];

        for (int j = 1; j < sibling->n; j++) {
            sibling->keys[j - 1] = sibling->keys[j];
        }

        if (!sibling->leaf) {
            for (int j = 1; j <= sibling->n; j++) {
                sibling->children[j - 1] = sibling->children[j];
            }
        }

        child->n += 1;
        sibling->n -= 1;
    }

    void fill(Node* node, int i) {
        if (i != 0 && node->children[i - 1]->n >= t) {
            borrowFromPrev(node, i);
        } else if (i != node->n && node->children[i + 1]->n >= t) {
            borrowFromNext(node, i);
        } else {
            if (i != node->n) {
                merge(node, i);
            } else {
                merge(node, i - 1);
            }
        }
    }

    void deleteKey(Node* node, int k) {
        int i = findKey(node, k);

        if (i < node->n && node->keys[i] == k) {
            if (node->leaf) {
                for (int j = i + 1; j < node->n; ++j)
                    node->keys[j - 1] = node->keys[j];
                node->n--;
            } else {
                if (node->children[i]->n >= t) {
                    int pred = getPredecessor(node, i);
                    node->keys[i] = pred;
                    deleteKey(node->children[i], pred);
                } else if (node->children[i + 1]->n >= t) {
                    int succ = getSuccessor(node, i);
                    node->keys[i] = succ;
                    deleteKey(node->children[i + 1], succ);
                } else {
                    merge(node, i);
                    deleteKey(node->children[i], k);
                }
            }
        }
        else {
            if (node->leaf)
                return;
    
            bool flag = (i == node->n);
    
            if (node->children[i]->n < t)
                fill(node, i);
    
            if (flag && i > node->n)
                deleteKey(node->children[i - 1], k);
            else
                deleteKey(node->children[i], k);
        }
    }

    bool search(Node* root, int target) {
        int i = 0;
    
        while (i < root->n && target > root->keys[i]) {
            i++;
        }
    
        if (i < root->n && target == root->keys[i]) {
            return true;
        }
    
        if (root->leaf) {
            return false;
        }
    
        return search(root->children[i], target);
    }

    void traverse(Node* root) {
        if (root == nullptr) return;
    
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf) {
                traverse(root->children[i]);
            }
            std::cout << root->keys[i] << " ";
        }

        if (!root->leaf) {
            traverse(root->children[i]);
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            if (!node->leaf) {
                for (int i = 0; i <= node->n; i++) {
                    destroyTree(node->children[i]);
                }
            }
            delete[] node->keys;
            delete[] node->children;
            delete node;
        }
    }

    Node* root;
    int t;
public:
    BTree(int t) : t(t), root(nullptr) {}

    ~BTree() {
        destroyTree(root);
    }
    
    void insert(int k) {
        if (!root) {
            root = new Node(t, true);
            root->keys[0] = k;
            root->n = 1; 
        } else {
            if (root->n == 2 * t - 1) {
                Node* s = new Node(t, false);
                s->children[0] = root;
                splitChild(s, 0, root);

                int i = 0;
                if (k > s->keys[0]) {
                    i++;
                }
                insertNonFull(s->children[i], k);
                root = s;
            } else {
                insertNonFull(root, k);
            }
        }
    }

    void deleteKey(int k) {
        if (!root) return;
    
        deleteKey(root, k);
    
        if (root->n == 0) {
            Node* temp = root;
            if (root->leaf) {
                root = nullptr;
            } else {
                root = root->children[0];
            }
            delete temp;
        }
    }

    bool search(int target) {
        return search(root, target);
    }

    void traverse() {
        traverse(root);
    }

};

int main() {
    BTree t(3);  // A B-Tree with minimum degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    t.traverse();
    std::cout << std::endl;

    t.deleteKey(7);
    t.deleteKey(30);
    t.traverse();
    std::cout << std::endl;

    std::cout << "Search 17: " << (t.search(17) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 50: " << (t.search(50) ? "Found" : "Not Found") << std::endl;
    return 0;
}