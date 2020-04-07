#include <vector>
#include <iostream>

void PrintVector(const std::vector<int>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

class DHeap {
public:
    DHeap(const std::vector<int>& heap_, int d_) {
        heap = heap_;
        d = d_;
        BuildHeap();
    }

    int Parent(int i) {
        return (i + d - 1) / d - 1;
    }

    int Child (int parent, int child) {
        return parent * d + child + 1;
    }

    int GetMin() {
        return heap[0];
    }

    int ExtractMin() {
        if (heap.size() < 1) {
            std::cout << "Heap is empty" << std::endl;
            return -1000000000;
        }

        int min = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        Heapify(0, heap.size());
        return min;
    }

    void DecreaseKey(int i, int key) {
        if (key > heap[i]) {
            std::cout << "Error, the key is too large" << std::endl;
            return ;
        }

        heap[i] = key;
        while (i > 0 && heap[Parent(i)] > heap[i]) {
            int t = heap[i];
            heap[i] = heap[Parent(i)];
            heap[Parent(i)] = t;

            i = Parent(i);

        }
    }

    void MinInsert(int key) {
        heap.push_back(10000);
        DecreaseKey(heap.size() - 1, key);
    }
    std::vector<int> heap;

private:
    void Heapify(int i, int heap_size) {
        int l = Child(i, 0);
        int r = Child(i, d - 1);
        int smallest = i;
        int prev = -1;

        while (smallest != prev) {
            prev = smallest;
            l = Child(smallest, 0);
            r = Child(smallest, d - 1);
            smallest = prev;

            for (int j = l; j <= r && j <= heap_size; j++) {
                if (heap[j] < heap[smallest]) {
                    smallest = j;
                }
            }

            if (smallest != prev) {
                int t = heap[prev];
                heap[prev] = heap[smallest];
                heap[smallest] = t;
            }
        }
    }

    void BuildHeap() {
        for (int i = heap.size() / d - 1; i >= 0; i--) {
            Heapify(i, heap.size() - 1);
        }
    }

    int d;
};

int main() {
    std::vector<int> heap = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

    PrintVector(heap);
    DHeap queue(heap, 3);
    PrintVector(queue.heap);
    queue.MinInsert(3);
    PrintVector(queue.heap);

    return 0;
}