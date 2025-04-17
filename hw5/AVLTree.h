#include <vector>
#include <queue>

class AVLTree {
private:
    struct node {
        int data;
        int height;
        node* left; node* right;
        node(int data) : data(data), height(1), left(nullptr), right(nullptr) {}
    };

    node* root;

    void clear(node* root);
    int getNodeHeight(node* root);
    int getBalanceFactor(node* root);
    node* getMinNode(node* root);
    node* rotateLeft(node* root);
    node* rotateRight(node* root);
    node* balance(node* root);
    node* insert(node* root, int data);
    node* remove(node* root, int data);
    std::vector<int> levelOrder(node* root);
public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        clear(root);
    }

    void insert(int data);
    void remove(int data);
    std::vector<int> levelOrder();
};