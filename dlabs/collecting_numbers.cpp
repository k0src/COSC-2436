#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    int size;
    std::cin >> size;

    std::vector<int> in;
    for (int i = 0; i < size; i++) {
        int num;
        std::cin >> num;
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

    std::cout << rounds;

    return 0;
}