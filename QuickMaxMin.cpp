#include <iostream>
#include <vector>

void FindMaxAndMin(const std::vector<int>& a, int *max, int *min) {
    size_t n = a.size();
    size_t i = n % 2 == 0 ? 0 : 1;

    *max = a[0];
    *min = a[0];

    for (; i + 1 < n; i += 2) {
        if (a[i] < a[i + 1]) {
            if (a[i] < *min) {
                *min = a[i];
            }

            if (a[i + 1] > *max) {
                *max = a[i + 1];
            }
        }
        else {
            if (a[i + 1] < *min) {
                *min = a[i + 1];
            }

            if (a[i] > *max) {
                *max = a[i];
            }
        }
    }
}

int main() {
    std::vector<int> a = {4, 20, -50, 50, -5};

    int max = -1, min = -1;
    FindMaxAndMin(a, &max, &min);

    std::cout << max << " " << min << std::endl;

    return 0;
}
