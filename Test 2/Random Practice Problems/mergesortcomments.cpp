#include "help.h"

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    // get sizes of both subarrays
    int n1 = mid - left + 1;    
    int n2 = right - mid;

    // create two temp arrays
    vector<int> t1(n1), t2(n2);

    // add elements to temp arrays from left and right subarrays
    for (int i = 0; i < n1; i++) 
        t1[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        t2[j] = arr[mid + 1 + j];
    
    // pointers for the temp arrays and the input array
    int k = left; // input
    int i = 0, j = 0; 

    // merge back sorted
    while (i < n1 && j < n2) {
        if (t1[i] <= t2[j]) {
            arr[k] = t1[i];
            i++;
        } else {
            arr[k] = t2[j];
            j++;
        }
        k++;
    }

    // merge any leftover elements
    while (i < n1) {
        arr[k] = t1[i];
        i++; 
        k++;
    }

    while (j < n2) {
        arr[k] = t2[j];
        j++;
        k++;
    }

}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    printVector(arr);
    mergeSort(arr, 0, arr.size() - 1);
    printVector(arr);

    return 0;
}