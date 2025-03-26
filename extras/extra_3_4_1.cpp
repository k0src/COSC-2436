#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <vector>

std::vector<int> createRandomArray() {
    int size, range;
    std::cout << "Enter size of array:" << std::endl;
    std::cin >> size;

    std::cout << "Enter range of numbers:" << std::endl;
    std::cin >> range;

    std::vector<int> res(size);

    for (int i = 0; i < size; i++) {
        res[i] = rand() % range;
    }

    return res;
}

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    std::srand(std::time(0));

    std::cout << "Time comparison: Shell Sort vs. Insertion Sort" << std::endl;

    while (true) {
        int choice;
        std::cout << "Choose:" << std::endl << "1. Insertion Sort" << std::endl
                  << "2. Shell Sort" << std::endl << "3. Exit" << std::endl;
        std::cin >> choice;
    
        if (choice == 1) {
            std::vector<int> arr = createRandomArray();
            auto i_start = std::chrono::high_resolution_clock::now();

            insertionSort(arr);

            auto i_end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time_taken = i_end - i_start;
            std::cout << "Time taken for Insertion Sort: " << time_taken.count() << " milliseconds" << std::endl;
        } else if (choice == 2) {
            std::vector<int> arr = createRandomArray();
            auto s_start = std::chrono::high_resolution_clock::now();

            shellSort(arr);

            auto s_end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time_taken = s_end - s_start;
            std::cout << "Time taken for Shell Sort: " << time_taken.count() << " milliseconds" << std::endl;
        } else {
            break;
        }
    }

    return 0;
}