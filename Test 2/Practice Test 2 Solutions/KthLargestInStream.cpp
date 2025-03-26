#include <iostream>
#include <vector>

using namespace std;

class KthLargestInStream {
private:
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
        void add(int item) {
            arr.push_back(item);
            int i = arr.size() - 1;

            while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
                swap(arr[i], arr[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }

        int min() const { 
            if (arr.empty()) {
                throw runtime_error("Heap is empty");
            }
            return arr[0]; 
        }

        void extractMin() {
            if (arr.size() == 0) return;

            if (arr.size() == 1) {
                arr.pop_back();
            } else {
                arr[0] = arr.back();
                arr.pop_back();
                minHeapify(0);
            }
        }

        int getSize() const { return arr.size(); }
    };

    MinHeap min_heap;
    int k;
public:
    KthLargestInStream(int k) : k(k) {}

    void add(int item) {
        min_heap.add(item);
        if (min_heap.getSize() > k) min_heap.extractMin();
    }

    int kthLargest() const {
        return min_heap.min();
    }
};

int main() 
{
    KthLargestInStream k(3);
    k.add(4);
    k.add(5);
    k.add(8);
    std::cout << k.kthLargest() << std::endl;
    k.add(3);
    std::cout << k.kthLargest() << std::endl; // 4
    k.add(5); 
    std::cout << k.kthLargest() << std::endl; // 5
    k.add(9);
    std::cout << k.kthLargest() << std::endl; // 8
}