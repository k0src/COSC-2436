#include <iostream>
#include <unordered_set>

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    std::unordered_set<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums.insert(num);
    }

    std::cout << nums.size();

    return 0;
}