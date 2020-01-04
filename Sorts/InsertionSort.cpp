#include <iostream>
#include <vector>

void PrintVector(const std::vector<double>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << std::endl;
        }
    }
}

void InsertionSort(std::vector<double>& v) {
    size_t n = v.size();
    
    for (size_t j = 1; j < n; j++) {
        double key = v[j];

        int i = j - 1;
        while (i >= 0 && v[i] <= key) {
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = key;
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

    InsertionSort(array);

    std::cout << "\nSorted: " << std::endl;
    PrintVector(array);

    return 0;
}