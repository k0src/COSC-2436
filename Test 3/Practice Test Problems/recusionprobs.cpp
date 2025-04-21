#include "help.h"

using namespace std;

int sumDigits(int n, int place = 1) {
    if (n / place == 0) {
        return 0;
    }

    return ((n / place) % 10) + sumDigits(n, place * 10);
}

int countZeroes(int n, int place = 1) {
    if (n / place == 0) {
        return 0;
    }

    if ((n / place) % 10 == 0) {
        return 1 + countZeroes(n, place * 10);
    } else {
        return countZeroes(n, place * 10);
    }
}

void generateSubsets(string s, string current = "", int index = 0) {
    if (index == s.length()) {
        cout << current << endl;
        return;
    }

    generateSubsets(s, current + s[index], index + 1);
    generateSubsets(s, current, index + 1);
}

int binarySearch(vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (target == arr[mid]) {
        return mid;
    } else if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, right, target);
    } else {
        return binarySearch(arr, left, mid - 1, target);
    }
}

int main()
{
    return 0;
}