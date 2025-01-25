#include <iostream>
#include <fstream>
#include <vector>
#include "ArgumentManager.h"

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const std::string input = am.get("input");
    const std::string output = am.get("output");

    ifstream file(input);
    ofstream ofile(output);

    int size;
    file >> size;

    std::vector<int> in;
    for (int i = 0; i < size; i++) {
        int num;
        file >> num;
        in.push_back(num);
    }

    int n = 1; // Input array always starts with 1
    int rounds = 0;

    while (n <= size) { // continue until n is larger than the size of the array
        rounds++;
        for (int j = 0; j < size; j++) {
            if (in[j] == n) {
                n++;
            }
        }
    }

    ofile << rounds;
    file.close();

    return 0;
}