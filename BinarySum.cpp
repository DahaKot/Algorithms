#include <iostream>
#include <vector>

void PrintVector(const std::vector<int>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << " ";
        }
    }
}

std::vector<int> Sum (const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> sum(a.size() + 1);

    for (int i = a.size() - 1; i >= 0; i--) {
        std::cout << "i: " << i << " sum: " << a[i] + b[i] << std::endl;
        sum[i+1] += (a[i] + b[i]) % 2;
        if (i != 0) {
            sum[i] = (a[i] + b[i]) / 2;
        }
    }

    return sum;
}

int main() {
    int n = -1;
    std::cin >> n;

    std::vector<int> a;
    std::vector<int> b;

    int x = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> x;
        a.push_back(x);
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> x;
        b.push_back(x);
    }

    std::cout << "sum is: " << std::endl;
    PrintVector(Sum(a, b));

    return 0;
}