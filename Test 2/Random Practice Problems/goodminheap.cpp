#include "help.h"

using namespace std;

class MinHeap {
private:
    void minHeapify(int i) {
        int smallest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < arr.size() && arr[left] < arr[smallest])
            smallest = left;
        if (right < arr.size() && arr[right] < arr[smallest])
            smallest = right;
            
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    vector<int> arr;
public:
    void insert(int item) {
        arr.push_back(item);
        int i = arr.size() - 1;

        while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int getMin() {
        if (arr.empty()) return -1;
        return arr[0];
    }

    int extractMin() {
        if (arr.empty()) return -1;
        
        int min = arr[0];
        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty()) {
            minHeapify(0);
        }

        return min;
    }
};

int main()
{
    MinHeap h;
    h.insert(4);
    h.insert(5);
    h.insert(10);
    h.insert(7);

    cout << h.extractMin();

    return 0;
}