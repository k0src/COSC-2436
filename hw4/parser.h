#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <vector>

struct ParsedInput {
    std::vector<std::string> command_lines;
    std::string traversal_method;
};

ParsedInput parseInputFile(std::ifstream& inFile) {
    ParsedInput parsed;
    std::string line, prev;

    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            prev = line;
            parsed.command_lines.push_back(line);
        }
    }

    parsed.command_lines.pop_back();
    parsed.traversal_method = prev;

    return parsed;
}

#endif