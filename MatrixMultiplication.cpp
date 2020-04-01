#include <vector>
#include <iostream>

void PrintMatrix(const std::vector<std::vector<int> >& a) {
    size_t n = a.size();
    size_t m = a[0].size();

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> MatrixMultiplication(
    const std::vector<std::vector<int>>& A, 
    const std::vector<std::vector<int>>& B) {
    int n = A.size();

    std::vector<std::vector<int>> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = std::vector<int> (n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main(int argc, char *argv[]) {
    int n = std::atoi(argv[1]);

    std::vector<std::vector<int>> A(n);
    int k = 2;
    for (int i = 0; i < n; i++) {
        A[i] = std::vector<int> (n);
        for (int j = 0; j < n; j++, k++) {
            A[i][j] = std::atoi(argv[k]);
        }
    }

    std::vector<std::vector<int>> B(n);
    for (int i = 0; i < n; i++) {
        B[i] = std::vector<int> (n);
        for (int j = 0; j < n; j++, k++) {
            B[i][j] = std::atoi(argv[k]);
        }
    }

    std::vector<std::vector<int>> C = MatrixMultiplication(A, B);

    return 0;
}