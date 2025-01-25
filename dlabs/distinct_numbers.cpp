#include <iostream>
#include <unordered_set>
#include <fstream>
#include "ArgumentManager.h"

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const std::string input = am.get("input");
    const std::string output = am.get("output");

    ifstream file(input);
    ofstream ofile(output);

    int n;
    file >> n;

    std::unordered_set<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        file >> num;
        nums.insert(num);
    }

    ofile << nums.size();

    file.close();

    return 0;
}