#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include "ArgumentManager.h"

struct Participant {
    std::string name;
    int black;
    int red;
};

bool parseParticipants(std::ifstream& inFile, std::queue<Participant>& participants) {
    std::string line;
    while (std::getline(inFile, line)) {
        Participant p;
        size_t commaPos = line.find(",");
        if (commaPos == std::string::npos) continue;
        
        p.name = line.substr(0, commaPos);
        p.name.erase(p.name.find_last_not_of(" ") + 1);
        std::string numPart = line.substr(commaPos + 1);
        numPart.erase(0, numPart.find_first_not_of(" "));

        int fullNum = std::stoi(numPart);
        
        p.black = fullNum / 10;
        p.red = fullNum % 10;
        
        participants.push(p);
    }

    return !participants.empty();
}

void parseCommands(std::ifstream& commandFile, std::stack<std::pair<char, int>>& commands) {
    std::string line;
    while (std::getline(commandFile, line)) {
        std::pair<char, int> p;
        p.first = line.at(0);
        p.second = std::stoi(line.substr(1));
        commands.push(p);
    }
}

void playGame(std::queue<Participant>& participants, std::stack<std::pair<char, int>>& commands, std::ofstream& outFile) {
    if (participants.empty()) {
        return;
    }
    
    if (commands.empty()) {
        while (!participants.empty()) {
            outFile << participants.front().name << "\n";
            participants.pop();
        }
        return;
    }
    
    while (!commands.empty() && !participants.empty()) {
        std::pair<char, int> currentCard = commands.top();
        char color = currentCard.first;
        int amount = currentCard.second;
        
        bool cardNeeded = false;
        int queueSize = participants.size();
        for (int i = 0; i < queueSize; i++) {
            Participant p = participants.front();
            participants.pop();
            
            if ((color == 'R' && p.red > 0) || (color == 'B' && p.black > 0)) {
                cardNeeded = true;
            }
            
            participants.push(p);
        }

        if (!cardNeeded) {
            commands.pop();
            continue;
        }
        
        Participant current = participants.front();
        participants.pop();
        
        if ((color == 'R' && current.red > 0) || (color == 'B' && current.black > 0)) {
            if (color == 'R') {
                if (amount >= current.red) {
                    amount -= current.red;
                    current.red = 0;
                    
                    if (amount == 0) {
                        commands.pop();
                    } else {
                        auto currentCommand = commands.top();
                        commands.pop();
                        currentCommand.second = amount;
                        commands.push(currentCommand);
                    }
                    
                    if (current.black != 0) {
                        participants.push(current);
                    }
                } else {
                    current.red -= amount;
                    commands.pop();
                    participants.push(current);
                }
            } else {
                if (amount >= current.black) {
                    amount -= current.black;
                    current.black = 0;
                    
                    if (amount == 0) {
                        commands.pop();
                    } else {
                        auto currentCommand = commands.top();
                        commands.pop();
                        currentCommand.second = amount;
                        commands.push(currentCommand);
                    }
                    
                    if (current.red != 0) {
                        participants.push(current);
                    }
                } else {
                    current.black -= amount;
                    commands.pop();
                    participants.push(current);
                }
            }
        } else {
            participants.push(current);
        }
    }

    if (participants.empty()) {
        outFile << "No Loser!\n";
    } else {
        while (!participants.empty()) {
            outFile << participants.front().name << "\n";
            participants.pop();
        }
    }
}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    std::ifstream inFile(am.get("input"));
    std::ifstream commandFile(am.get("command"));
    std::ofstream outFile(am.get("output"));
    
    if (!inFile.is_open() || !outFile.is_open() || !commandFile.is_open()) {
        return 1;
    }

    std::queue<Participant> participants;

    if (!parseParticipants(inFile, participants)) {
        outFile << "No Game!";
        return 0;
    }

    std::stack<std::pair<char, int>> commands;
    parseCommands(commandFile, commands);

    playGame(participants, commands, outFile);

    inFile.close();
    outFile.close();
    commandFile.close();

    return 0;
}