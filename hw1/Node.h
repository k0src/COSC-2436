#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
	Node(const std::string& name, int age, int deposit, int n_drinks) : name(name), age(age), deposit(deposit), n_drinks(n_drinks), next(nullptr) {}
private:
	std::string name;
	int age;
	int deposit;
	int n_drinks; 

	Node* next;

	friend class LinkedList;
};

#endif