#include <iostream>

class TreeMap {
private:
    struct MapNode {
        int key, value;
        int height;
        MapNode*left; MapNode* right;
        MapNode(int key, int value) : key(key), value(value), height(1), left(nullptr), right(nullptr) {}
    };

    MapNode* root;

    int getNodeHeight(MapNode* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalanceFactor(MapNode* node) {
        if (!node) return 0;
        return getNodeHeight(node->left) - getNodeHeight(node->right);
    }

    void clear(MapNode* root) {
        if (!root) return;
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }

    MapNode* rotateRight(MapNode* y) {
        MapNode* x = y->left;
        MapNode* T2 = x->right;
    
        x->right = y;
        y->left = T2;
    
        y->height = 1 + std::max(getNodeHeight(y->left), getNodeHeight(y->right));
        x->height = 1 + std::max(getNodeHeight(x->left), getNodeHeight(x->right));
    
        return x;
    }
    
    MapNode* rotateLeft(MapNode* x) {
        MapNode* y = x->right;
        MapNode* T2 = y->left;
    
        y->left = x;
        x->right = T2;
    
        x->height = 1 + std::max(getNodeHeight(x->left), getNodeHeight(x->right));
        y->height = 1 + std::max(getNodeHeight(y->left), getNodeHeight(y->right));
    
        return y;
    }

    MapNode* insert(MapNode* root, int key, int value) {
        if (!root) return new MapNode(key, value);
    
        if (key < root->key)
            root->left = insert(root->left, key, value);
        else if (key > root->key)
            root->right = insert(root->right, key, value);
        else {
            root->value = value;
            return root;
        }

        root->height = 1 + std::max(getNodeHeight(root->left), getNodeHeight(root->right));
        int balance = getBalanceFactor(root);
    
        // Left Left
        if (balance > 1 && key < root->left->key)
            return rotateRight(root);
    
        // Right Right
        if (balance < -1 && key > root->right->key)
            return rotateLeft(root);
    
        // Left Right
        if (balance > 1 && key > root->left->key) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    
        // Right Left
        if (balance < -1 && key < root->right->key) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    
        return root;
    }
    

    MapNode* minNode(MapNode* root) {
        MapNode* current = root;

        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    MapNode* remove(MapNode* root, int key) {
        if (!root) return nullptr;

        if (key > root->key) {
            root->right = remove(root->right, key);
        } else if (key < root->key) {
            root->left = remove(root->left, key);
        } else {
            if (!root->left) {
                MapNode* temp = root->right;
                delete root;
                root = nullptr;
                return temp;
            } else if (!root->right) {
                MapNode* temp = root->left;
                delete root;
                root = nullptr;
                return temp;
            } else {
                MapNode* min_node = minNode(root->right);
                root->key = min_node->key;
                root->value = min_node->value;
                root->right = remove(root->right, min_node->key);
            }
        }

        root->height = 1 + std::max(getNodeHeight(root->left), getNodeHeight(root->right));
        int balance = getBalanceFactor(root);

        // Left Left
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rotateRight(root);

        // Left Right
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return rotateLeft(root);

        // Right Left
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }   

        return root;
    }

    int get(MapNode* root, int key) {
        if (!root) return -1;

        if (key > root->key) {
            return get(root->right, key);
        } else if (key < root->key) {
            return get(root->left, key);
        } else {
            return root->value;
        }
    }

    bool contains(MapNode* root, int key) {
        if (!root) return false;

        if (key > root->key) {
            return contains(root->right, key);
        } else if (key < root->key) {
            return contains(root->left, key);
        } else {
            return true;
        }
    }

    int size(MapNode* root) {
        if (!root) return 0;

        return size(root->left) + size(root->right) + 1;
    }

    void print(MapNode* root) {
        if (!root) return;

        print(root->left);
        std::cout << "[" << root->key << ", " << root->value << "]\n";
        print(root->right);
    }

public:
    TreeMap() : root(nullptr) {}

    ~TreeMap() {
        clear(root);
        root = nullptr;
    }

    void insert(int key, int value) {
        root = insert(root, key, value);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    int get(int key) {
        return get(root, key);
    }
    
    bool contains(int key) {
        return contains(root, key);
    }
    
    int size() {
        return size(root);
    }

    void clear() {
        clear(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void print() {
        print(root);
    }
};

int main()
{
    TreeMap map;
    map.insert(1, 44);
    map.insert(3, 69);
    map.insert(5, 31);
    map.insert(7, 77);
    map.insert(7, 76);
    map.insert(6, 29);
    map.insert(10, 22);
    map.insert(0, 96);
    map.insert(8, 13);
    map.insert(9, 97);
    map.insert(11, 55);
    map.insert(2, 64);

    map.remove(6);
    map.remove(0);

    std::cout << map.size() << std::endl; // 4
    std::cout << map.get(1) << std::endl; // 44
    std::cout << map.contains(1) << std::endl; // 1

    map.print();

    return 0;
}