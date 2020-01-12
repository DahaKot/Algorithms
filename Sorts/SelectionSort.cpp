#include <iostream>
#include <vector>

void PrintVector(const std::vector<double>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << " ";
        }
    }
}

void SelectionSort(std::vector<double>& v) {
    size_t n = v.size();
    double min_idx = 0;

    for (size_t i = 0; i < n - 1; i++) {
        min_idx = i;
        for (size_t j = i; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        double t = v[i];
        v[i] = v[min_idx];
        v[min_idx] = t;
    }
}

int main() {
    std::vector<double> array;
    double x = 0;

    size_t n = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        std::cin >> x;
        array.push_back(x);
    }

    std::cout << "Usorted: " << std::endl;
    PrintVector(array);

    SelectionSort(array);

    std::cout << "\nSorted: " << std::endl;
    PrintVector(array);

    return 0;
}