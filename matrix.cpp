#include <iostream>
#include <time.h>
using namespace std;

void multiply(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n = 1024;
    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    // Initialize matrices with random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    clock_t start, end;

    // Measure time taken for matrix multiplication with different loop orders
    start = clock();
    multiply(A, B, C, n);
    end = clock();
    cout << "Time taken for matrix multiplication with ijk loop order: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    start = clock();
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = clock();
    cout << "Time taken for matrix multiplication with jik loop order: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    start = clock();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = clock();
    cout << "Time taken for matrix multiplication with kij loop order: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
