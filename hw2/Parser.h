#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype> 
#include "Playlist.h"

void ParseInput(std::ifstream& inFile, std::ofstream& outFile, Playlist& p);

#endif