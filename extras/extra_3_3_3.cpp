#include <iostream>

class Tree {
public:
    Tree() : _root(nullptr) {}

    void insert(int value) {
        _root = insertNode(value, _root);
    }

    bool search(int value) {
        return searchTree(value, _root);
    }

    void printInorder() {
        traverseInorder(_root);
        std::cout << std::endl;
    }

    void printPreorder() {
        traversePreorder(_root);
        std::cout << std::endl;
    }

    void printPostorder() {
        traversePostorder(_root);
        std::cout << std::endl;
    }
    
    private:
    struct Node {
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
        
        int value;
        Node* left;
        Node* right;
    };
    
    Node* insertNode(int value, Node* root) {
        if (!root) {
            return new Node(value);
        }
        
        if (value < root->value) 
        root->left = insertNode(value, root->left);
        else if (value > root->value) 
        root->right = insertNode(value, root->right);
        
        return root;
    }
    
    bool searchTree(int value, Node* root) {
        if (!root) return false;
        
        else if (value < root->value) 
        return searchTree(value, root->left);
        else if (value > root->value) 
        return searchTree(value, root->right);
        
        return true;
    }
    
    void traverseInorder(Node* root) {
        if (!root) return;

        traverseInorder(root->left);
        std::cout << root->value << " ";
        traverseInorder(root->right);
    }

    void traversePreorder(Node* root) {
        if (!root) return;

        std::cout << root->value << " ";
        traversePreorder(root->left);
        traversePreorder(root->right);
    }

    void traversePostorder(Node* root) {
        if (!root) return;

        traversePostorder(root->left);
        traversePostorder(root->right);
        std::cout << root->value << " ";
    }

    Node* _root;
};

int main() 
{
    Tree t;
    t.insert(1);
    t.insert(5);
    t.insert(6);
    t.insert(2);
    t.insert(9);
    t.insert(8);

    std::cout << t.search(1) << std::endl;
    std::cout << t.search(0) << std::endl;

    t.printInorder();
    t.printPreorder();
    t.printPostorder();

    return 0;
}