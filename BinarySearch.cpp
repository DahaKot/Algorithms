#include <iostream>
#include <vector>

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

int main() {
    std::vector<double> array;
    double x = 0;

    size_t n = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        std::cin >> x;
        array.push_back(x);
    }

    std::cin >> x;

    std::cout << FindX(x, array) << std::endl;

    return 0;
}