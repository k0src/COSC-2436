#include <fstream>
#include "ArgumentManager.h"
#include "parser.h"
#include "queue.h"

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ofstream outFile(am.get("output"));
    
    if (!inFile.is_open() || !outFile.is_open()) {
        return 1;
    }

    // Parse input
    auto parsed = parseInputFile(inFile);
    CommandQueue cq;

    // Add commands to queue
    for (const auto& line : parsed.command_lines) {
        cq.addCommand(line);
    }

    // Execute commands
    while (!cq.commandQueueIsEmpty()) {
        cq.executeFrontCommand();
        cq.popCommand();
    }

    // Traverse BST, output messages in that order
    const std::vector<std::string>& traversal =
    (parsed.traversal_method == "Preorder") ? cq.getBST().traversePreOrder() :
    (parsed.traversal_method == "Inorder")  ? cq.getBST().traverseInOrder() :
                                              cq.getBST().traversePostOrder();

    for (int i = 0; i < traversal.size(); i++) {
        outFile << traversal[i];
        if (i < traversal.size() - 1) {
            outFile << std::endl;
        }
    }

    inFile.close();
    outFile.close();

    return 0;
}