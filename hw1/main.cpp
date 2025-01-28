#include <iostream>
#include <string>
#include "ArgumentManager.h"
#include "LinkedList.h"
#include <fstream>

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ifstream commandFile(am.get("command"));
    std::ofstream outFile(am.get("output"));

    if (!inFile.is_open() || !outFile.is_open() || !commandFile.is_open()) {
        return 1;
    }

    LinkedList list;

    list.parseFile(inFile);
    list.parseCommandFile(commandFile);
    list.printToFile(outFile);

    inFile.close();
    outFile.close();
	
	return 0;
}