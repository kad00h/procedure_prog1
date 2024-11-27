#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transposeMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[N][N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Початкова матриця:\n");
    printMatrix(matrix);

    transposeMatrix(matrix);

    printf("Транспонована матриця:\n");
    printMatrix(matrix);

    return 0;
}