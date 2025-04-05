#include "queue.h"

CommandQueue::CommandQueue() {
    order = 0;
    // Register commands
    command_map["DECODE"] = []() { return std::make_shared<DecodeCommand>(); };
    command_map["REPLACE"] = []() { return std::make_shared<ReplaceCommand>(); };
    command_map["ADD"] = []() { return std::make_shared<AddCommand>(); };
    command_map["SWAP"] = []() { return std::make_shared<SwapCommand>(); };
    command_map["REMOVE"] = []() { return std::make_shared<RemoveCommand>(); };
    command_map["BST"] = []() { return std::make_shared<BSTCommand>(); };
}

void CommandQueue::addCommand(const std::string& line) {
    std::string id = line.substr(0, line.find(':'));
    std::vector<std::string> args;

    std::string args_str = line.substr(line.find('[') + 1, line.find(']') - line.find('[') - 1);
    std::stringstream ss(args_str);
    std::string arg;
    while (std::getline(ss, arg, ',')) {
        args.push_back(arg);
    }

    int priority = std::stoi(line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));

    if (command_map.find(id) == command_map.end()) {
        throw std::runtime_error("Command not found: " + id);
    }

    auto command = command_map[id]();
    command->setPriority(priority);
    command->setArgs(args);
    command->setOrder(order++);
    command_queue.push(std::move(command));
}

void CommandQueue::executeFrontCommand() {
    if (command_queue.empty()) return;

    const auto command = command_queue.top();
    command->execute(message_queue, bst);
}

void CommandQueue::popCommand() {
    if (command_queue.empty()) {
        throw std::runtime_error("Queue is empty");
    }

    command_queue.pop();
}

bool CommandQueue::commandQueueIsEmpty() const {
    return command_queue.empty();
}

BinarySearchTree& CommandQueue::getBST() {
    return bst;
}