#include <iostream>
#include <vector>
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

int Select(std::vector<int>& a, int i) {
    size_t n = a.size();

    int start = 0;
    int end = n - 1;

    while (start < end) {
        int q = 0, t = 0;

        srand (time(nullptr));
        int p = rand() % (end - start + 1);

        Partition(a, start, end, p, &q, &t);
        int k = q - start + 1;

        if (i == k) {
            return a[q];
        }
        else if (i < k) {
            end = q - 1;
        }
        else {
            start = t + 1;
            i = i - k;
        }
    }

    return a[start];
}

int main() {
    std::vector<int> a = {4, 20, -50, 50, -5, 56, 34, 90};
    PrintVector(a);

    std::cout << "7: " << Select(a, 7) << std::endl;

    return 0;
}
