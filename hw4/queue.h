#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include "commands.h"
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <functional>
#include <memory>
#include "BinarySearchTree.h"

class CommandQueue {
public:
    CommandQueue();
    void addCommand(const std::string& line);
    void executeFrontCommand();
    void popCommand();
    bool commandQueueIsEmpty() const;
    BinarySearchTree& getBST();
private:
    int order;

    struct CommandCompare {
        bool operator()(const std::shared_ptr<Command>& c1, const std::shared_ptr<Command>& c2) const {
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
                        std::vector<std::shared_ptr<Command>>,
                        CommandCompare> command_queue;

    std::queue<std::string> message_queue;
    BinarySearchTree bst;

    std::unordered_map<std::string, std::function<std::shared_ptr<Command>()>> command_map;
};

#endif