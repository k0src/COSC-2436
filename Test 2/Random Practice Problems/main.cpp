#include "help.h"

using namespace std;

void countingSort(vector<int>& arr, int n, int place) {
    vector<int> count_array(10, 0);

    for (int i : arr) {
        count_array[(i / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--) {
        res[count_array[(arr[i] / place) % 10] - 1] = arr[i];
        count_array[(arr[i] / place) % 10]--;
    }

    arr = res;  
}

void radixSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int n = arr.size();

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

int main()
{
    vector<int> arr = {314, 882, 90, 182, 69, 199, 422, 999};
    radixSort(arr);
    printVector(arr);
    return 0;
}