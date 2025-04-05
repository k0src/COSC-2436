#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

struct Command {
    virtual ~Command() = default;
    virtual void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) = 0;
    virtual void setArgs(std::vector<std::string>& args) = 0;
    virtual void setPriority(int priority) = 0;
    virtual int getPriority() = 0;
    virtual void setOrder(int order) = 0;
    virtual int getOrder() = 0;
};

struct DecodeCommand : Command {
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override {
        message_queue.push(args[0]);
    }

    void setArgs(std::vector<std::string>& args) override {
        this->args = args;
    }

    int getPriority() override {
        return priority;
    }

    void setPriority(int priority) override {
        this->priority = priority;
    }

    void setOrder(int order) override {
        this->order = order;
    }

    int getOrder() override {
        return order;
    }

    int priority;
    int order;
    std::vector<std::string> args;
};

struct ReplaceCommand : Command {    
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override { 
        std::string front = message_queue.front();
        message_queue.pop();

        size_t pos = 0;
        while ((pos = front.find(args[0], pos)) != std::string::npos) {
            front.replace(pos, args[0].length(), args[1]);
            pos += args[1].length();
        }

        message_queue.push(front);
    }

    void setArgs(std::vector<std::string>& args) override {
        this->args = args;
    }

    int getPriority() override {
        return priority;
    }

    void setPriority(int priority) override {
        this->priority = priority;
    }

    void setOrder(int order) override {
        this->order = order;
    }

    int getOrder() override {
        return order;
    }

    int priority;
    int order;
    std::vector<std::string> args;
};

struct AddCommand : Command {
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override {
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

    void setArgs(std::vector<std::string>& args) override {
        this->args = args;
    }

    int getPriority() override {
        return priority;
    }

    void setPriority(int priority) override {
        this->priority = priority;
    }

    void setOrder(int order) override {
        this->order = order;
    }

    int getOrder() override {
        return order;
    }

    int priority;
    int order;
    std::vector<std::string> args;
};

struct SwapCommand : Command {    
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override {
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

    void setArgs(std::vector<std::string>& args) override {
        this->args = args;
    }

    int getPriority() override {
        return priority;
    }

    void setPriority(int priority) override {
        this->priority = priority;
    }

    void setOrder(int order) override {
        this->order = order;
    }

    int getOrder() override {
        return order;
    }

    int priority;
    int order;
    std::vector<std::string> args;
};

struct RemoveCommand : Command {
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override {        
        std::string front = message_queue.front();
        message_queue.pop();

        size_t pos = 0;
        while ((pos = front.find(args[0], pos)) != std::string::npos) {
            front.erase(pos, args[0].length());
        }

        message_queue.push(front);
    }

    void setArgs(std::vector<std::string>& args) override {
        this->args = args;
    }

    int getPriority() override {
        return priority;
    }

    void setPriority(int priority) override {
        this->priority = priority;
    }

    void setOrder(int order) override {
        this->order = order;
    }

    int getOrder() override {
        return order;
    }

    int priority;
    int order;
    std::vector<std::string> args;
};

struct BSTCommand : Command {
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override {
        if (!message_queue.empty()) {
            bst.insert(message_queue.front());
            message_queue.pop();
        }
    }

    void setArgs(std::vector<std::string>& args) override {
        this->args = args;
    }

    int getPriority() override {
        return priority;
    }

    void setPriority(int priority) override {
        this->priority = priority;
    }

    void setOrder(int order) override {
        this->order = order;
    }

    int getOrder() override {
        return order;
    }

    int priority;
    int order;
    std::vector<std::string> args;
};

#endif