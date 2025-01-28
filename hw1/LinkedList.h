#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <fstream>

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void parseInputFile(std::ifstream& inFile);
	void parseCommandFile(std::ifstream& inFile);
	void addEnd(const std::string& name, int age, int deposit, int n_drinks);
	void add(int index, const std::string& name, int age, int deposit, int n_drinks);
	void removeNode(Node* node);
	void removeByName(const std::string& name);
	void removeByAge(int age);
	void removeByDeposit(int deposit);
	void removeByNdrinks(int n_drinks);
	void sortByName();
	void sortByAge();
	void sortByDeposit();
	void sortByNdrinks();

	int size() const;
	void clear();
	bool contains(Node* node);
	Node* find(const std::string& name, int age);
	void printToFile(std::ofstream& outFile);
	void updateNode(Node* node, int deposit, int n_drinks);

private:
	Node* head;
	Node* tail;
	int _size = 0;
};

#endif