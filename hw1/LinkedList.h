#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <fstream>
#include <iostream> // delete me

class LinkedList {
public:
	enum Attribute {
		NAME,
		AGE,
		DEPOSIT,
		N_DRINKS
	};

	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList() {
		clear();
	}

	void parseFile(std::ifstream& inFile) {
		std::string line;
		std::getline(inFile, line);
		if (line.find("Add") != std::string::npos || line.find("Remove") != std::string::npos || line.find("Sort") != std::string::npos) {
			inFile.seekg(0);
			parseCommandFile(inFile);
		} else {
			inFile.seekg(0);
			parseInputFile(inFile);
		}
	}

	void parseInputFile(std::ifstream& inFile) {
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

	void parseCommandFile(std::ifstream& inFile) {
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
				// sort
			}
		}
	}

	void addEnd(const std::string& name, int age, int deposit, int n_drinks) {
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

	void add(int index, const std::string& name, int age, int deposit, int n_drinks) {
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

	void removeNode(Node* node) {
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

	void removeByName(const std::string& name) {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;
			if (current->name == name) {
				removeNode(current);
			}
			current = nextNode;
		}
	}

	void removeByAge(int age) {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;
			if (current->age == age) {
				removeNode(current);
			}
			current = nextNode;
		}
	}

	void removeByDeposit(int deposit) {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;
			if (current->deposit == deposit) {
				removeNode(current);
			}
			current = nextNode;
		}
	}

	void removeByNdrinks(int n_drinks) {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;
			if (current->n_drinks == n_drinks) {
				removeNode(current);
			}
			current = nextNode;
		}
	}

	int size() const {
		return _size;
	}

	void clear() {
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

	bool contains(Node* node) {
		Node* current = head;
		while (current) {
			if (current->name == node->name && current->age == node->age) return true;
			current = current->next;
		}
		return false;
	}

	Node* find(const std::string& name, int age) {
		Node* current = head;
		while (current) {
			if (current->name == name && current->age == age) return current;
			current = current->next;
		}
		return nullptr;
	}

	void printToFile(std::ofstream& outFile) {
		Node* current = head;
		while (current) {
			outFile << "[name: " << current->name << "; age: " << current->age << "; deposit: " << current->deposit << "; number of drinks: " << current->n_drinks << "]" << std::endl;
			current = current->next;
		}
	}

	void updateNode(Node* node, int deposit, int n_drinks) {
		node->deposit = deposit;
		node->n_drinks = n_drinks;
	}

private:
	Node* head;
	Node* tail;
	int _size = 0;
};

#endif