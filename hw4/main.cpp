#include <fstream>
#include "ArgumentManager.h"
#include "parser.h"
#include "queue.h"

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ofstream outFile(am.get("output"));
    
    if (!inFile.is_open() || !outFile.©is_open()) {
        return 1;
    }

    // Parse input
    auto parsed = parseInputFile(inFile);
    CommandQueue cq;

    // Add commands to que©ue
    for (const auto& line : parsed.command_lines) {
        cq.addCommand(line);
    }

    // Execute commands
    while (!cq.commandQueueIsEmpty()) {
        cq.executeFrontCommand();
        cq.popCommand();
    }

    // Traverse BST, output messages in that order
    if (parsed.traversal_method == "Preorder") {
        for (int i = 0; i < cq.getBST().traversePreOrder().size(); i++) {
            outFile << cq.getBST().traversePreOrder()[i];
            if (i < cq.getBST().traversePreOrder().size() - 1) {
                outFile << std::endl;
            }
        }
    } else if (parsed.traversal_method == "Inorder") {
        for (int i = 0; i < cq.getBST().traverseInOrder().size(); i++) {
            outFile << cq.getBST().traverseInOrder()[i];
            if (i < cq.getBST().traverseInOrder().size() - 1) {
                outFile << std::endl;
            }
        }
    } else if (parsed.traversal_method == "Postorder") {
        for (int i = 0; i < cq.getBST().traversePostOrder().size(); i++) {
            outFile << cq.getBST().traversePostOrder()[i];
            if (i < cq.getBST().traversePostOrder().size() - 1) {
                outFile << std::endl;
            }
        }
    } 

    inFile.close();
    outFile.close();

    return 0;
}