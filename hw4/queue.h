#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include "commands.h"
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "BinarySearchTree.h"

class CommandQueue {
public:
    CommandQueue() {
        order = 0;
        // Register commands
        command_map["DECODE"] = []() { return std::make_shared<DecodeCommand>(); };
        command_map["REPLACE"] = []() { return std::make_shared<ReplaceCommand>(); };
        command_map["ADD"] = []() { return std::make_shared<AddCommand>(); };
        command_map["SWAP"] = []() { return std::make_shared<SwapCommand>(); };
        command_map["REMOVE"] = []() { return std::make_shared<RemoveCommand>(); };
        command_map["BST"] = []() { return std::make_shared<BSTCommand>(); };
    }

    void addCommand(const std::string& line) {
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

    void executeFrontCommand() {
        if (command_queue.empty()) return;

        auto command = std::move(command_queue.top());
        command->execute(message_queue, bst);
    }

    void popCommand() {
        if (command_queue.empty()) {
            throw std::runtime_error("Queue is empty");
        }

        command_queue.pop();
    }

    bool commandQueueIsEmpty() const {
        return command_queue.empty();
    }

    BinarySearchTree& getBST() {
        return bst;
    }

private:
    int order;

    struct CommandCompare {
        bool operator()(const std::shared_ptr<Command>& c1, const std::shared_ptr<Command>& c2) {
            int p1 = c1->getPriority();
            int p2 = c2->getPriority();

            if (p1 == p2) {
                return c1->getOrder() > c2->getOrder();
            } else {
                return p1 > p2;
            }
        }
    };

    std::priority_queue<std::shared_ptr<Command>,
        std::vector<std::shared_ptr<Command>>, CommandCompare> command_queue;

    std::queue<std::string> message_queue;
    BinarySearchTree bst;

    std::unordered_map<std::string, std::function<std::shared_ptr<Command>()>> command_map;
};

#endif