#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList::~LinkedList() {
    clear();
}

void LinkedList::parseInputFile(std::ifstream& inFile) {
    std::string line;
    while (getline(inFile, line)) {
        std::string name = line.substr(line.find("name:") + 6, line.find(";", line.find("name:")) - line.find("name:") - 6);
        name.erase(0, name.find_first_not_of(" \t"));
        name.erase(name.find_last_not_of(" \t") + 1);
        int age = std::stoi(line.substr(line.find("age:") + 4, line.find(";", line.find("age:")) - line.find("age:") - 4));
        int deposit = std::stoi(line.substr(line.find("deposit:") + 8, line.find(";", line.find("deposit:")) - line.find("deposit:") - 8));
        int n_drinks = std::stoi(line.substr(line.find("number of drinks:") + 17, line.find("]", line.find("number of drinks:")) - line.find("number of drinks:") - 17));

        addEnd(name, age, deposit, n_drinks);
    }
}

void LinkedList::parseCommandFile(std::ifstream& inFile) {
    std::string line;
    while (getline(inFile, line)) {
        if (line.find("Add") != std::string::npos) {
            int index = line.find("(") + 1;
            int end = line.find(")");
            std::string index_str = line.substr(index, end - index);
            int index_int = std::stoi(index_str);

            std::string name = line.substr(line.find("name:") + 6, line.find(";", line.find("name:")) - line.find("name:") - 6);
            name.erase(0, name.find_first_not_of(" \t"));
            name.erase(name.find_last_not_of(" \t") + 1);
            int age = std::stoi(line.substr(line.find("age:") + 4, line.find(";", line.find("age:")) - line.find("age:") - 4));
            int deposit = std::stoi(line.substr(line.find("deposit:") + 8, line.find(";", line.find("deposit:")) - line.find("deposit:") - 8));
            int n_drinks = std::stoi(line.substr(line.find("number of drinks:") + 17, line.find("]", line.find("number of drinks:")) - line.find("number of drinks:") - 17));

            add(index_int, name, age, deposit, n_drinks);
        } else if (line.find("Remove") != std::string::npos) {
            if (line.find("number of drinks:") != std::string::npos) {
                int n_drinks = std::stoi(line.substr(line.find("number of drinks:") + 17, line.find("]", line.find("number of drinks:")) - line.find("number of drinks:") - 17));
                removeByNdrinks(n_drinks);
            } else if (line.find("name:") != std::string::npos) {
                std::string name = line.substr(line.find("name:") + 6, line.find(")", line.find("name:")) - line.find("name:") - 6);
                name.erase(0, name.find_first_not_of(" \t"));
                name.erase(name.find_last_not_of(" \t") + 1);
                removeByName(name);
            } else if (line.find("age:") != std::string::npos) {
                int age = std::stoi(line.substr(line.find("age:") + 4, line.find(";", line.find("age:")) - line.find("age:") - 4));
                removeByAge(age);
            } else if (line.find("deposit:") != std::string::npos) {
                int deposit = std::stoi(line.substr(line.find("deposit:") + 8, line.find(";", line.find("deposit:")) - line.find("deposit:") - 8));
                removeByDeposit(deposit);
            }
        } else if (line.find("Sort") != std::string::npos) {
            if (line.find("number of drinks") != std::string::npos) {
                sortByNdrinks();
            } else if (line.find("deposit") != std::string::npos) {
                sortByDeposit();
            } else if (line.find("name") != std::string::npos) {
                sortByName();
            } else if (line.find("age") != std::string::npos) {
                sortByAge();
            }
        }
    }
}

void LinkedList::addEnd(const std::string& name, int age, int deposit, int n_drinks) {
    Node* node = new Node(name, age, deposit, n_drinks);

    if (contains(node)) {
        delete node;
        updateNode(find(name, age), deposit, n_drinks);
        return;
    }

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    _size++;
}

void LinkedList::add(int index, const std::string& name, int age, int deposit, int n_drinks) {
    if (index < 0) {
        return;
    }

    Node* node = new Node(name, age, deposit, n_drinks);

    if (contains(node)) {
        delete node;
        updateNode(find(name, age), deposit, n_drinks);
        return;
    }

    if (index >= _size) {
        delete node;
        addEnd(name, age, deposit, n_drinks);
        return;
    }

    if (index == 0) {
        node->next = head;
        head = node;
        _size++;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    _size++;
}

void LinkedList::removeNode(Node* node) {
    if (node == head) {
        head = node->next;
    } else {
        Node* current = head;
        while (current->next != node) {
            current = current->next;
        }
        current->next = node->next;
    }
    delete node;
    _size--;
}

void LinkedList::removeByName(const std::string& name) {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        if (current->name == name) {
            removeNode(current);
        }
        current = nextNode;
    }
}

void LinkedList::removeByAge(int age) {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        if (current->age == age) {
            removeNode(current);
        }
        current = nextNode;
    }
}

void LinkedList::removeByDeposit(int deposit) {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        if (current->deposit == deposit) {
            removeNode(current);
        }
        current = nextNode;
    }
}

void LinkedList::removeByNdrinks(int n_drinks) {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        if (current->n_drinks == n_drinks) {
            removeNode(current);
        }
        current = nextNode;
    }
}

void LinkedList::sortByName() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;

        while (current->next) {
            if (current->name > current->next->name) {
                swapped = true;

                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (prev) {
                    prev->next = temp;
                } else {
                    head = temp;
                }

                prev = temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

void LinkedList::sortByAge() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;

        while (current->next) {
            if (current->age > current->next->age) {
                swapped = true;

                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (prev) {
                    prev->next = temp;
                } else {
                    head = temp;
                }

                prev = temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

void LinkedList::sortByDeposit() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;

        while (current->next) {
            if (current->deposit > current->next->deposit) {
                swapped = true;

                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (prev) {
                    prev->next = temp;
                } else {
                    head = temp;
                }

                prev = temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}


void LinkedList::sortByNdrinks() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;

        while (current->next) {
            if (current->n_drinks > current->next->n_drinks) {
                swapped = true;

                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (prev) {
                    prev->next = temp;
                } else {
                    head = temp;
                }

                prev = temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

int LinkedList::size() const {
    return _size;
}

void LinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

bool LinkedList::contains(Node* node) {
    Node* current = head;
    while (current) {
        if (current->name == node->name && current->age == node->age) return true;
        current = current->next;
    }
    return false;
}

Node* LinkedList::find(const std::string& name, int age) {
    Node* current = head;
    while (current) {
        if (current->name == name && current->age == age) return current;
        current = current->next;
    }
    return nullptr;
}

void LinkedList::printToFile(std::ofstream& outFile) {
    Node* current = head;
    while (current) {
        outFile << "[name: " << current->name << "; age: " << current->age << "; deposit: " << current->deposit << "; number of drinks: " << current->n_drinks << "]" << std::endl;
        current = current->next;
    }
}

void LinkedList::updateNode(Node* node, int deposit, int n_drinks) {
    node->deposit = deposit;
    node->n_drinks = n_drinks;
} 