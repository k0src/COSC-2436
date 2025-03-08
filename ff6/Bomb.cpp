#include <iostream>
#include <vector>

void bombGame(std::vector<int>& arr, int k) {
    std::vector<int> res(arr.size());

    if (k == 0) {
        for (int i = 0; i < arr.size(); i++) {
            res[i] = 0;
        }
        arr = res;
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                sum += arr[(i + j) % arr.size()];
            }
        } else {
            for (int j = -1; j >= k; j--) {
                sum += arr[(i + j + arr.size()) % arr.size()];
            }
        }
        res[i] = sum;
    }

    arr = res;
}


int main()
{
    std::vector<int> a1 = {5, 7, 1, 4};
    std::vector<int> a2 = {1, 2, 3, 4};
    std::vector<int> a3 = {2, 4, 9, 3};

    bombGame(a1, 3);
    std::cout << "a1" << std::endl;
    for (int i : a1) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    bombGame(a2, 0);
    std::cout << "a2" << std::endl;
    for (int i : a2) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    bombGame(a3, -2);
    std::cout << "a3" << std::endl;
    for (int i : a3) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}