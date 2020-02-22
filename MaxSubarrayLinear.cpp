#include <vector>
#include <iostream>
#include <cstdlib>

struct Subarray {
    int begin_index;
    int end_index;
    int sum;
};

void PrintVector(const std::vector<int>& v) {
    size_t n = v.size();

    for (size_t i = 0; i < n; i++) {
        std::cout << v[i];
        if (i != n - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

Subarray FindMaximumSubarray(const std::vector<int>& array) {
    int n = array.size();

    int sum = 0;
    int subsum = 0;
    int min_sum = 0;
    int min_index = 0;
    Subarray max_subarray = {0, 0, array[0]};

    for (int i = 0; i < n; i++) {
        sum += array[i];

        subsum = sum - min_sum;
        if (subsum > max_subarray.sum) {
            max_subarray.end_index = i;
            max_subarray.sum = subsum;
            max_subarray.begin_index = min_index + 1;
        }

        if (sum < min_sum) {
            min_sum = sum;
            min_index = i;
        }
    }

    return max_subarray;
} 

int main(int argc, char *argv[]) {
    int n = std::atoi(argv[1]);

    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] += std::atoi(argv[i + 2]);
    }
    // PrintVector(array);

    Subarray max_subarray = FindMaximumSubarray(array);

    // std::cout << "Max_subarray starts from: " << max_subarray.begin_index
    //         << " ends on: " << max_subarray.end_index
    //         << " and has sum: " << max_subarray.sum << std::endl;

    return 0;
}