#include <iostream>
#include <vector>

int FindX (double x, const std::vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) {
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