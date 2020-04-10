#include <vector>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

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

void Swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void Partition(std::vector<int>& a, int start, int end, int p, int *q, int *t) {
    int x = a[start + p];
    a[start + p] = a[end];
    a[end] = x;

    int i = start - 1;
    *t = end;

    for (int j = start; j <= end; j++) {
        if (a[j] < x) {
            i++;
            Swap(&a[i], &a[j]);
        }
        else if (a[j] == x && *t > j) {
            (*t)--;
            Swap(&a[*t], &a[j]);
            j--;
        }
    }

    *q = i + 1;
    for (int k = *t; k <= end; k++) {
        Swap(&a[i+1], &a[k]);
        i++;
    }
    *t = i;
}

void QuickSort (std::vector<int>& a, int start, int end) {
    if (start >= end) {
        return ;
    }

    int q = -1, t = -1;
    srand (time(nullptr));

    int p = rand() % (end - start + 1);

    Partition(a, start, end, p, &q, &t);

    QuickSort(a, start, q - 1);
    QuickSort(a, t + 1, end);
}

int main() {
    std::vector<int> array = {10, 1, 1, 1, 1, 1};

    PrintVector(array);
    QuickSort(array, 0, array.size() - 1);
    PrintVector(array);

    return 0;
}