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

void CountingSort(std::vector<int>& v, int k) {
    size_t n = v.size();
    std::vector<int> counts(k);
    std::vector<int> new_v(n);

    for (int i = 0; i < k; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        counts[v[i]]++;
    }

    for (int i = 1; i < k; i++) {
        counts[i] = counts[i - 1] + counts[i];
    }

    for (int j = n - 1; j >= 0; j--) {
        new_v[counts[v[j]] - 1] = v[j];

        counts[v[j]]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = new_v[i];
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

    CountingSort(array, 10);

    std::cout << "\nSorted: " << std::endl;
    PrintVector(array);

    return 0;
}
