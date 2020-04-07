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

class Queue {
public:
    Queue(const std::vector<int>& heap_) {
        heap = heap_;
        BuildHeap();
    }

    int Parent(int i) {
        return (i + 1) / 2 - 1;
    }

    int Left(int i) {
        return 2 * i + 1;
    }

    int Right(int i) {
        return 2 * i + 2;
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
        int l = Left(i);
        int r = Right(i);
        int smallest = i;
        int prev = -1;

        while (smallest != prev) {
            prev = smallest;
            l = Left(smallest);
            r = Right(smallest);
            smallest = l;

            if (l <= heap_size && heap[l] < heap[prev]) {
                smallest = l;
            }
            else {
                smallest = prev;
            }

            if (r <= heap_size && heap[r] < heap[smallest]) {
                smallest = r;
            }

            if (smallest != prev) {
                int t = heap[prev];
                heap[prev] = heap[smallest];
                heap[smallest] = t;
            }
        }
    }

    void BuildHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            Heapify(i, heap.size() - 1);
        }
    }
};

int main() {
    std::vector<int> heap = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

    PrintVector(heap);
    Queue queue(heap);
    PrintVector(queue.heap);
    queue.MinInsert(3);
    PrintVector(queue.heap);

    return 0;
}