#include <iostream>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const std::string input = am.get("input");
    const std::string output = am.get("output");

    ifstream file(input);
    ofstream ofile(output);

    int n, k;
    file >> n >> k;

    std::vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        file >> num;
        nums.push_back(num);
    }

    std::vector<int> temp;

    for (int i = 0; i <= n - k; i++) {
        for (int j = i; j < i + k; j++) {
            temp.push_back(nums[j]);
        }
        std::sort(temp.begin(), temp.end());
        ofile << temp[temp.size() / 2] << " ";
        temp.clear();
    }

    file.close();

    return 0;
}