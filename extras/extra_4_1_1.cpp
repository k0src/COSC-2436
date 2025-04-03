#include <iostream>
#include <ctime>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* root_node = nullptr;

TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }

    if (value == root->data) {
        return root;
    } else if (value < root->data) {
        root->left = insertIntoBST(root->left, value);
    } else {
        root->right = insertIntoBST(root->right, value);
    }
    return root;
}

void insertValue() {
    int value;
    std::cout << "Enter value to insert:\n";
    std::cin >> value;

    root_node = insertIntoBST(root_node, value);
}

void insertRandomValue() {
    int range, n;
    std::cout << "Enter random range:\n";
    std::cin >> range;
    std::cout << "Enter number of random values:\n";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value = rand() % range;
        root_node = insertIntoBST(root_node, value);
    }

    std::cout << "Inserted " << n << " random values in the range " << range << " into the binary tree." << std::endl;
}

void insertOption() {
    int choice;
    std::cout << "Insertion:\n1. Insert Value\n2. Insert Random Value\n3. Exit" << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        insertValue();
        break;
    case 2:
        insertRandomValue();
        break;
    case 3:
        break;
    default:
        break;
    }
}

void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInorder(root->left);
    std::cout << root->data << " ";
    printInorder(root->right);
}

void printInorderOption(TreeNode* root) {
    if(!root) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::cout << "Inorder Traversal:\n";
    printInorder(root);
    std::cout << std::endl;
}

void search(TreeNode* root, int value) {
    if (!root) {
        std::cout << "Value not found in the tree." << std::endl;
        return;
    }

    if (value == root->data) {
        std::cout << "Value found: " << root->data << std::endl;
        return;
    } else if (value < root->data) {
        search(root->left, value);
    } else {
        search(root->right, value);
    }
}

void searchOption() {
    if (!root_node) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    int value;
    std::cout << "Enter value to search:\n";
    std::cin >> value;

    search(root_node, value);
}

void printMenu() {
    std::cout << "\nBinary Tree Operations\n1. Insert\n2. Search\n3. Print Inorder\n4. Exit" << std::endl;
}

int main()
{
    srand(time(0));
    int choice;

    while (choice != 4) {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            insertOption();
            break;
        case 2:
            searchOption();
            break;
        case 3:
            printInorderOption(root_node);
            break;
        case 4:
            break;
        default:
            break;
        }
    }

    return 0;
}