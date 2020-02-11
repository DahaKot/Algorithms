#include <vector>
#include <iostream>

void PrintVector(const std::vector<double>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
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

int FindX (double x, const std::vector<double>& v) {
    size_t n = v.size();

    size_t begin = 0, end = n - 1;
    while (begin <= end) {
        size_t i = (begin + end) / 2;
        if (v[i] < x) {
            begin = i + 1;
        }
        else if (v[i] > x){
            end = i - 1;
        }
        else {
            return i;
        }
    }

    return -1;
}

void FindAndPrintTwoElementsWithSumX(std::vector<double> array, double x) {
    MergeSort(array, 0, array.size() - 1);

    for (int i = 0; i < array.size(); i++) {
        int k = FindX(x - array[i], array);
        if (k > i) {
            std::cout << array[i] << " " << array[k] << std::endl;
            return;
        }
    }

    std::cout << "Not such pair found" << std::endl;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<double> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    double x = 0;
    std::cin >> x;

    FindAndPrintTwoElementsWithSumX(array, x);

    return 0;
}