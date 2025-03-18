#include <iostream>
#include <vector>
#include <cmath>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Start with the largest gap using Shell's sequence: floor(N / 2^k)
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform an insertion sort for each gap interval
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Store the current element
            int j = i;
            
            // Shift elements in the sorted part to the right to make room for temp
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            
            // Place temp in its correct position
            arr[j] = temp;
        }
    }
}

int main()
{
    std::vector<int> arr = {1, 5, 21, 23, 63, 4, 12, 8, 5, 76, 45, 43, 39, 90, 97, 47, 82, 16, 17, 28};
    shellSort(arr);

    for (int i : arr) {
        std::cout << i << " ";
    }
    
    return 0;
}