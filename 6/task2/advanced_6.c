#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fill_array(int* arr) {
    srand(time(0));
    for (int i = 0; i < SIZE * SIZE; i++) {
        *(arr + i) = rand() % 11;
    }
}

void process_zeros(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (*(arr + i * SIZE + j) == 0) {
                // Заповнюємо рядок i нулями
                for (int k = 0; k < SIZE; k++) {
                    *(arr + i * SIZE + k) = 0;
                }
                // Заповнюємо колонку j нулями
                for (int k = 0; k < SIZE; k++) {
                    *(arr + k * SIZE + j) = 0;
                }
            }
        }
    }
}

void print_array(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", *(arr + i * SIZE + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[SIZE][SIZE];
    fill_array((int*)arr);

    printf("Generated 2D array:\n");
    print_array((int*)arr);

    process_zeros((int*)arr);

    printf("\nProcessed 2D array:\n");
    print_array((int*)arr);

    return 0;
}
