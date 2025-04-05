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
    virtual std::string getID() = 0;
};

struct DecodeCommand : Command {
    DecodeCommand() : priority(0), order(0) {}
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override;
    void setArgs(std::vector<std::string>& args) override;
    int getPriority() override;
    void setPriority(int priority) override;
    void setOrder(int order) override;
    int getOrder() override;
    std::string getID() override;

private:
    int priority;
    int order;
    std::vector<std::string> args;
};

struct ReplaceCommand : Command {
    ReplaceCommand() : priority(0), order(0) {}
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override;
    void setArgs(std::vector<std::string>& args) override;
    int getPriority() override;
    void setPriority(int priority) override;
    void setOrder(int order) override;
    int getOrder() override;
    std::string getID() override;

private:
    int priority;
    int order;
    std::vector<std::string> args;
};

struct AddCommand : Command {
    AddCommand() : priority(0), order(0) {}
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override;
    void setArgs(std::vector<std::string>& args) override;
    int getPriority() override;
    void setPriority(int priority) override;
    void setOrder(int order) override;
    int getOrder() override;
    std::string getID() override;

private:
    int priority;
    int order;
    std::vector<std::string> args;
};

struct SwapCommand : Command {
    SwapCommand() : priority(0), order(0) {}
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override;
    void setArgs(std::vector<std::string>& args) override;
    int getPriority() override;
    void setPriority(int priority) override;
    void setOrder(int order) override;
    int getOrder() override;
    std::string getID() override;

private:
    int priority;
    int order;
    std::vector<std::string> args;
};

struct RemoveCommand : Command {
    RemoveCommand() : priority(0), order(0) {}
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override;
    void setArgs(std::vector<std::string>& args) override;
    int getPriority() override;
    void setPriority(int priority) override;
    void setOrder(int order) override;
    int getOrder() override;
    std::string getID() override;

private:
    int priority;
    int order;
    std::vector<std::string> args;
};

struct BSTCommand : Command {
    BSTCommand() : priority(0), order(0) {}
    void execute(std::queue<std::string>& message_queue, BinarySearchTree& bst) override;
    void setArgs(std::vector<std::string>& args) override;
    int getPriority() override;
    void setPriority(int priority) override;
    void setOrder(int order) override;
    int getOrder() override;
    std::string getID() override;

private:
    int priority;
    int order;
    std::vector<std::string> args;
};

#endif