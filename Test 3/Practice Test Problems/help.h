#ifndef HELP_H
#define HELP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <limits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <list>
#include <cstring>
#include <bitset>
#include <array>
#include <numeric>
#include <sstream>
#include <iterator>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addBack(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int& value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    void insertHelper(TreeNode*& node, const int& value) {
        if (!node) {
            node = new TreeNode(value);
        } else if (value < node->data) {
            insertHelper(node->left, value);
        } else {
            insertHelper(node->right, value);
        }
    }

    void printHelper(TreeNode* node) const {
        if (node) {
            std::cout << node->data << " ";
            printHelper(node->left);
            printHelper(node->right);
        }
    }

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        std::function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
            if (node) {
                deleteTree(node->left);
                deleteTree(node->right);
                delete node;
            }
        };
        deleteTree(root);
    }

    void insert(const int& value) {
        insertHelper(root, value);
    }

    void print() const {
        printHelper(root);
        std::cout << std::endl;
    }
};

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printStack(std::stack<T> stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void printQueue(std::queue<T> queue) {
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void printList(const std::list<T>& lst) {
    for (const T& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename K, typename V>
void printUnorderedMap(const std::unordered_map<K, V>& umap) {
    for (const auto& pair : umap) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;
}

template <typename K, typename V>
void printMap(const std::map<K, V>& map) {
    for (const auto& pair : map) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;
}

template <typename T>
void printUnorderedSet(const std::unordered_set<T>& uset) {
    for (const T& elem : uset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printSet(const std::set<T>& set) {
    for (const T& elem : set) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif