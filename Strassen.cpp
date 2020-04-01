#include <vector>
#include <iostream>

void PrintMatrix(const std::vector<std::vector<int> >& a) {
    size_t n = a.size();
    size_t m = n;
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> StrassenMatrixMultiplication(
    const std::vector<std::vector<int>>& A, 
    const std::vector<std::vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        std::vector<std::vector<int>> C(n);
        C[0] = std::vector<int> (n);

        C[0][0] = A[0][0] * B[0][0];

        return C;
    }

    // 1. Creating S-matrices
    std::vector<std::vector<std::vector<int>>> S(10);

    for (int i = 0; i < 10; i++) {
        S[i] = std::vector<std::vector<int>> (n/2);
        for (int j = 0; j < n/2; j++) {
            S[i][j] = std::vector<int> (n/2);
        }
    }

    std::vector<std::vector<int>> A11(n/2);
    std::vector<std::vector<int>> B11(n/2);
    std::vector<std::vector<int>> A22(n/2);
    std::vector<std::vector<int>> B22(n/2);

    for (int i = 0; i < n/2; i++) {
        A11[i] = std::vector<int> (n/2);
        B11[i] = std::vector<int> (n/2);
        A22[i] = std::vector<int> (n/2);
        B22[i] = std::vector<int> (n/2);

        for (int j = 0; j < n/2; j++) {
            S[0][i][j] = B[i][j + n/2] - B[i + n/2][j + n/2];
            S[1][i][j] = A[i][j] + A[i][j + n/2];
            S[2][i][j] = A[i + n/2][j] + A[i + n/2][j + n/2];
            S[3][i][j] = B[i + n/2][j] - B[i][j];
            S[4][i][j] = A[i][j] + A[i + n/2][j + n/2];
            S[5][i][j] = B[i][j] + B[i + n/2][j + n/2];
            S[6][i][j] = A[i][j + n/2] - A[i + n/2][j + n/2];
            S[7][i][j] = B[i + n/2][j] + B[i + n/2][j + n/2];
            S[8][i][j] = A[i][j] - A[i + n/2][j];
            S[9][i][j] = B[i][j] + B[i][j + n/2];

            A11[i][j] = A[i][j];
            B11[i][j] = B[i][j];
            A22[i][j] = A[i + n/2][j + n/2];
            B22[i][j] = B[i + n/2][j + n/2];
        }
    }

    // 2. Creating P-matrices

    std::vector<std::vector<std::vector<int>>> P(7);

    for (int i = 0; i < 7; i++) {
        P[i] = std::vector<std::vector<int>> (n/2);
        for (int j = 0; j < n/2; j++) {
            P[i][j] = std::vector<int> (n/2);
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            P[0] = StrassenMatrixMultiplication(A11, S[0]);
            P[1] = StrassenMatrixMultiplication(S[1], B22);
            P[2] = StrassenMatrixMultiplication(S[2], B11);
            P[3] = StrassenMatrixMultiplication(A22, S[3]);
            P[4] = StrassenMatrixMultiplication(S[4], S[5]);
            P[5] = StrassenMatrixMultiplication(S[6], S[7]);
            P[6] = StrassenMatrixMultiplication(S[8], S[9]);
        }
    }

    // 3. Getting C = A * B

    std::vector<std::vector<int>> C(n);

    for (int i = 0; i < n; i++) {
        C[i] = std::vector<int> (n);
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j] = P[4][i][j] + P[3][i][j] - P[1][i][j] + P[5][i][j];
            C[i][j + n/2] = P[0][i][j] + P[1][i][j];
            C[i + n/2][j] = P[2][i][j] + P[3][i][j];
            C[i + n/2][j + n/2] = P[4][i][j] + P[0][i][j] - P[2][i][j] - P[6][i][j];
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

    std::vector<std::vector<int>> C = StrassenMatrixMultiplication(A, B);

    return 0;
}