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

int Parent(int i) {
    return i / 2;
}

int Left(int i) {
    return 2 * i + 1;
}

int Right(int i) {
    return 2 * i + 2;
}

void MaxHeapify(std::vector<int>& heap, int i, int heap_size) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    int prev = -1;

    while (largest != prev) {
        prev = largest;
        l = Left(largest);
        r = Right(largest);
        largest = l;

        if (l <= heap_size && heap[l] > heap[prev]) {
            largest = l;
        }
        else {
            largest = prev;
        }

        if (r <= heap_size && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != prev) {
            int t = heap[prev];
            heap[prev] = heap[largest];
            heap[largest] = t;
        }
    }
}

void BuildMaxHeap(std::vector<int>& heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        MaxHeapify(heap, i, heap.size() - 1);
    }
}

void HeapSort(std::vector<int>& heap) {
    BuildMaxHeap(heap);
    for (int i = heap.size() - 1; i >= 1; i--) {
        int t = heap[0];
        heap[0] = heap[i];
        heap[i] = t;
        MaxHeapify(heap, 0, i - 1);
    }
}

int main() {
    std::vector<int> heap = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};

    PrintVector(heap);
    HeapSort(heap);
    PrintVector(heap);

    return 0;
}