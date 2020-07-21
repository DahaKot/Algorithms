#include <iostream>
#include <vector>
#include <math.h>

void PrintVector(const std::vector<int>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << std::endl;
        }
    }
}

void CountingSortByRank(std::vector<int>& v, int k) {
    size_t n = v.size();
    std::vector<int> counts(10);
    std::vector<int> new_v(n);

    int index = -1;

    for (int i = 0; i < n; i++) {
        index = static_cast <int> (v[i] / pow(10, k)) % 10;
        counts[index]++;
    }

    for (int i = 1; i < 10; i++) {
        counts[i] = counts[i - 1] + counts[i];
    }

    for (int j = n - 1; j >= 0; j--) {
        index = static_cast <int> (v[j] / pow(10, k)) % 10;
        new_v[counts[index] - 1] = v[j];

        counts[index]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = new_v[i];
    }
}

void RadixSort(std::vector<int>& v, int k) {
    for (int i = 0; i < k; i++) {
        CountingSortByRank(v, i);
    }
}

int main() {
    std::vector<int> array;
    double x = 0;

    size_t n = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        std::cin >> x;
        array.push_back(x);
    }

    std::cout << "Usorted: " << std::endl;
    PrintVector(array);

    RadixSort(array, 4);

    std::cout << "\nSorted: " << std::endl;
    PrintVector(array);

    return 0;
}
