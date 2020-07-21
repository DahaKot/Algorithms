#include <iostream>
#include <vector>

void PrintVector(const std::vector<int>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << std::endl;
        }
    }
}

void InsertionSort(std::vector<int>& v) {
    size_t n = v.size();

    for (size_t j = 1; j < n; j++) {
        double key = v[j];

        int i = j - 1;
        while (i >= 0 && v[i] > key) {
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = key;
    }
}

void BucketSort(std::vector<int>& v) {
    size_t n = v.size();
    std::vector<std::vector<int>> buckets(10);

    for (int i = 0; i < n; i++) {
        buckets[v[i] / 10].push_back(v[i]);
    }

    for (int j = 0; j < 10; j++) {
        InsertionSort(buckets[j]);
        // std::cout << "\nbucket #" << j << std::endl;
        // PrintVector(buckets[j]);
    }

    // std::cout << "segfault" << std::endl;

    for (int i = 0, k = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            v[k] = buckets[i][j];
            k++;
        }
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

    BucketSort(array);

    std::cout << "\nSorted: " << std::endl;
    PrintVector(array);

    return 0;
}
