#include "help.h"

using namespace std;

void bucketSort(vector<double>& arr) {
    int n = arr.size();
    vector<vector<double>> buckets(n);

    for (double d : arr) {
        int index = (int) d * n;
        buckets[index].push_back(d);
    }

    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    int i = 0;
    for (auto& bucket : buckets) {
        for (double d : bucket) {
            arr[i++] = d;
        }
    }
}

int main()
{
    vector<double> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(arr);
    printVector(arr);
    return 0;
}