#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include "AVLTree.h"

void parseCommand(const std::string& command, AVLTree& avl) {
    std::string c = command.substr(0, command.find('('));
    int arg = stoi(command.substr(command.find('(') + 1, command.find(')') - command.find('(') - 1));

    if (c == "Insert") {
        avl.insert(arg);
    } else if (c == "Remove") {
        avl.remove(arg);
    } else {
        std::cerr << "Invalid command" << std::endl;
    }
}

void outputLevelOrder(AVLTree& avl, std::ofstream& outFile) {
    std::vector<int> levelOrder = avl.levelOrder();
    
    for (int i = 0; i < levelOrder.size(); i++) {
        if (levelOrder[i] == -1) {
            outFile << std::endl;
        } else {
            outFile << levelOrder[i];
            if (i + 1 < levelOrder.size() && levelOrder[i + 1] != -1) {
                outFile << " ";
            }
        }
    }
}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ofstream outFile(am.get("output"));
    
    if (!inFile.is_open() || !outFile.is_open()) {
        return 1;
    }
 
    AVLTree avl;

    std::string line;
    while (std::getline(inFile, line)) {
        parseCommand(line, avl);
    }

    outputLevelOrder(avl, outFile);

    inFile.close();
    outFile.close();

    return 0;
}