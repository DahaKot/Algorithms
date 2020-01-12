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

void Merge(std::vector<double>& v, int begin, int delimeter, int end) {
    std::vector<double> left;
    std::vector<double> right;

    for (int i = begin; i < delimeter + 1; i++) {
        left.push_back(v[i]);
    }
    for (int i = delimeter + 1; i < end + 1; i++) {
        right.push_back(v[i]);
    }

    for (int i = 0, j = 0, k = begin; k <= end; k++) {
        if (i >= left.size()) {
            v[k] = right[j];
            j++;
            continue;
        }
        if (j >= right.size()) {
            v[k] = left[i];
            i++;
            continue;
        }

        if (left[i] < right[j]) {
            v[k] = left[i];
            i++;
        }
        else {
            v[k] = right[j];
            j++;
        }
    }
}

void MergeSort(std::vector<double>& v, int begin, int end) {
    if (begin < end) {
        int delimeter = (end + begin) / 2;

        MergeSort(v, begin, delimeter);
        MergeSort(v, delimeter + 1, end);

        Merge(v, begin, delimeter, end);
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

    MergeSort(array, 0, array.size() - 1);

    std::cout << "\nSorted: " << std::endl;
    PrintVector(array);

    return 0;
}