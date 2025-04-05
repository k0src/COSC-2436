#include "commands.h"

// DECODE
void DecodeCommand::execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) {
    message_queue.push(args[0]);
}

void DecodeCommand::setArgs(std::vector<std::string>& args) {
    this->args = args;
}

int DecodeCommand::getPriority() {
    return priority;
}

void DecodeCommand::setPriority(int priority) {
    this->priority = priority;
}

void DecodeCommand::setOrder(int order) {
    this->order = order;
}

int DecodeCommand::getOrder() {
    return order;
}

std::string DecodeCommand::getID() {
    return "DECODE";
}

// REPLACE
void ReplaceCommand::execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) {
    if (message_queue.empty()) return;

    std::string front = message_queue.front();
    message_queue.pop();

    size_t pos = 0;
    while ((pos = front.find(args[0], pos)) != std::string::npos) {
        front.replace(pos, args[0].length(), args[1]);
        pos += args[1].length();
    }

    message_queue.push(front);
}

void ReplaceCommand::setArgs(std::vector<std::string>& args) {
    this->args = args;
}

int ReplaceCommand::getPriority() {
    return priority;
}

void ReplaceCommand::setPriority(int priority) {
    this->priority = priority;
}

void ReplaceCommand::setOrder(int order) {
    this->order = order;
}

int ReplaceCommand::getOrder() {
    return order;
}

std::string ReplaceCommand::getID() {
    return "REPLACE";
}

// ADD
void AddCommand::execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) {
    if (message_queue.empty()) return;

    std::string front = message_queue.front();
    message_queue.pop();

    size_t pos = 0;
    while ((pos = front.find(args[0], pos)) != std::string::npos) {
        pos += args[0].length();
        front.insert(pos, args[1]);
        pos += args[1].length();
    }

    message_queue.push(front);
}

void AddCommand::setArgs(std::vector<std::string>& args) {
    this->args = args;
}

int AddCommand::getPriority() {
    return priority;
}

void AddCommand::setPriority(int priority) {
    this->priority = priority;
}

void AddCommand::setOrder(int order) {
    this->order = order;
}

int AddCommand::getOrder() {
    return order;
}

std::string AddCommand::getID() {
    return "ADD";
}

// SWAP
void SwapCommand::execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) {
    if (message_queue.empty()) return;

    if (args[0] == args[1]) return;

    std::string front = message_queue.front();
    message_queue.pop();
    std::string temp = "$$TEMP$$";

    while (front.find(temp) != std::string::npos) {
        temp += "$$";
    }

    size_t pos = 0;
    while ((pos = front.find(args[0], pos)) != std::string::npos) {
        front.replace(pos, args[0].length(), temp);
        pos += temp.length();
    }

    pos = 0;
    while ((pos = front.find(args[1], pos)) != std::string::npos) {
        front.replace(pos, args[1].length(), args[0]);
        pos += args[0].length();
    }

    pos = 0;
    while ((pos = front.find(temp, pos)) != std::string::npos) {
        front.replace(pos, temp.length(), args[1]);
        pos += args[1].length();
    }

    message_queue.push(front);
}

void SwapCommand::setArgs(std::vector<std::string>& args) {
    this->args = args;
}

int SwapCommand::getPriority() {
    return priority;
}

void SwapCommand::setPriority(int priority) {
    this->priority = priority;
}

void SwapCommand::setOrder(int order) {
    this->order = order;
}

int SwapCommand::getOrder() {
    return order;
}

std::string SwapCommand::getID() {
    return "SWAP";
}

// REMOVE
void RemoveCommand::execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) {
    if (message_queue.empty()) return;

    std::string front = message_queue.front();
    message_queue.pop();

    size_t pos = 0;
    while ((pos = front.find(args[0], pos)) != std::string::npos) {
        front.erase(pos, args[0].length());
        if (args[0].empty()) break;
    }
    

    message_queue.push(front);
}

void RemoveCommand::setArgs(std::vector<std::string>& args) {
    this->args = args;
}

int RemoveCommand::getPriority() {
    return priority;
}

void RemoveCommand::setPriority(int priority) {
    this->priority = priority;
}

void RemoveCommand::setOrder(int order) {
    this->order = order;
}

int RemoveCommand::getOrder() {
    return order;
}

std::string RemoveCommand::getID() {
    return "REMOVE";
}

// BST
void BSTCommand::execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) {
    if (message_queue.empty()) return;

    bst.insert(message_queue.front());
    message_queue.pop();
}

void BSTCommand::setArgs(std::vector<std::string>& args) {
    this->args = args;
}

int BSTCommand::getPriority() {
    return priority;
}

void BSTCommand::setPriority(int priority) {
    this->priority = priority;
}

void BSTCommand::setOrder(int order) {
    this->order = order;
}

int BSTCommand::getOrder() {
    return order;
}

std::string BSTCommand::getID() {
    return "BST";
}