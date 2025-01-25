#include "vector.h"
#include "ArgumentManager.h"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ofstream outFile(am.get("output"));

    if (!inFile.is_open() || !outFile.is_open()) {
        return 1;
    }

    Vector vec;
    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command.find("Add(") == 0) {
            int x = std::stoi(command.substr(4, command.length() - 5));
            vec.Add(x);
        } else if (command.find("Delete(") == 0) {
            int x = std::stoi(command.substr(7, command.length() - 8));
            vec.Delete(x);
        } else if (command == "Print") {
            for (int i = 0; i < vec.getSize(); ++i) {
                outFile << vec[i];
                if (i < vec.getSize() - 1) outFile << " ";
            }
            outFile << std::endl;
        } else if (command == "Size") {
            outFile << vec.getSize() << std::endl;
        } else if (command == "Capacity") {
            outFile << vec.getCapacity() << std::endl;
        }
    }

    return 0;
}
