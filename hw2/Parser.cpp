#include "Parser.h"

void ParseInput(std::ifstream& inFile, std::ofstream& outFile, Playlist& p) {
    std::string line;

    while (std::getline(inFile, line)) {
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.empty()) continue;

        size_t openParen = line.find('(');
        size_t closeParen = line.find(')');

        if (openParen == std::string::npos || closeParen == std::string::npos) continue;

        std::string command = line.substr(0, openParen);
        std::string args = line.substr(openParen + 1, closeParen - openParen - 1);

        std::stringstream ss(args);
        std::string token;

        if (command == "AddSong") {
            std::string title;
            int duration;
            std::string favStr;
            bool fav_status;

            getline(ss, title, ',');
            title.erase(0, title.find_first_not_of(" \t\""));
            title.erase(title.find_last_not_of(" \t\"") + 1);

            getline(ss, token, ',');
            duration = std::stoi(token);

            getline(ss, favStr, ',');
            favStr.erase(std::remove_if(favStr.begin(), favStr.end(), ::isspace), favStr.end());
            fav_status = (favStr == "True");

            p.AddSong(title, duration, fav_status);
        } 
        else if (command == "PrintPlaylist") {
            p.PrintPlaylist(outFile);
        } 
        else if (command == "DeleteSong") {
            std::string title;
            getline(ss, title, ',');
            title.erase(0, title.find_first_not_of(" \t\""));
            title.erase(title.find_last_not_of(" \t\"") + 1);
            p.DeleteSong(title);
        } 
        else if (command == "PrintReversedPlaylist") {
            p.PrintReversedPlaylist(outFile);
        } 
        else if (command == "CreateSmartPlaylist") {
            int time_limit;
            ss >> time_limit;
            p.CreateSmartPlaylist(time_limit, outFile);
        }
    }
}
