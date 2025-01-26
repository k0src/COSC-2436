#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
	Node(const std::string& name, int price) : name(name), price(price), next(nullptr) {}

	std::string name;
	int price;
	Node* next;
};

#endif