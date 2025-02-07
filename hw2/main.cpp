#include "ArgumentManager.h"
#include <fstream>
#include "Playlist.h"
#include "Parser.h"

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ofstream outFile(am.get("output"));

    if (!inFile.is_open() || !outFile.is_open()) {
        return 1;
    }

    Playlist p;
    ParseInput(inFile, outFile, p);

    inFile.close();
    outFile.close();
	
	return 0;
}