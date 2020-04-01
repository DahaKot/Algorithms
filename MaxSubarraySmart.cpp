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

Subarray FindMaximumSubarrayBrute(const std::vector<int>& array, 
                                    int begin, 
                                    int end) {
    int n = end  - begin + 1;

    int max_sum = -1000;
    int low_index = -1;
    int high_index = -1;

    std::vector<int> sums(n);

    for (int i = begin, k = 0; i <= end; i++, k++) {
        for (int j = i; j >= 0; j--) {
            sums[k] += array[j];
        }
    }

    for (int low = begin; low <= end; low++) {
        for (int high = low; high <= end; high++) {
            int sum;
            if (low == 0) {
                sum = sums[high];
            }
            sum = sums[high] - sums[low - 1];

            if (sum > max_sum) {
                max_sum = sum;
                low_index = low;
                high_index = high;
            }
        }
    }

    return {low_index, high_index, max_sum};
}

Subarray FindMaxMiddleArray(const std::vector<int>& array, 
                            int begin, 
                            int end, 
                            int delimeter) {
    int max_left_sum = -1000;
    int max_right_sum = -1000;

    int left_index = -1;
    int right_index = -1;

    for (int i = delimeter, sum = 0; i >= begin; i--) {
        sum += array[i];
        if (sum > max_left_sum) {
            max_left_sum = sum;
            left_index = i;
        }
    }

    for (int i = delimeter + 1, sum = 0; i <= end; i++) {
        sum += array[i];
        if (sum > max_right_sum) {
            max_right_sum = sum;
            right_index = i;
        }
    }

    return {left_index, right_index, max_left_sum + max_right_sum};
}

Subarray FindMaximumSubarray(const std::vector<int>& array, int begin, int end) {
    int n = end  - begin + 1;

    if (n == 1) {
        return {begin, begin, array[begin]};
    }
    
    int delimeter = (begin + end) / 2;

    Subarray left_max = FindMaximumSubarray(array, begin, delimeter);
    Subarray right_max = FindMaximumSubarray(array, delimeter + 1, end);
    Subarray middle_max = FindMaxMiddleArray(array, begin, end, delimeter);

    if (left_max.sum > right_max.sum && left_max.sum > middle_max.sum) {
        return left_max;
    }
    else if (right_max.sum > left_max.sum && right_max.sum > middle_max.sum) {
        return right_max;
    }
    else {
        return middle_max;
    }
}

int main(int argc, char *argv[]) {
    int n = std::atoi(argv[1]);

    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] += std::atoi(argv[i + 2]);
    }
    // PrintVector(array);

    Subarray max_subarray = FindMaximumSubarray(array, 0, n - 1);

    // std::cout << "Smart: Max_subarray starts from: " << max_subarray.begin_index
    //         << " ends on: " << max_subarray.end_index
    //         << " and has sum: " << max_subarray.sum << std::endl;

    return 0;
}