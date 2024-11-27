#include <stdio.h>

void FillArray(int N) {
    char Array[N][N];

    // Заповнення масиву
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j || i + j == N - 1) {
                Array[i][j] = '*';
            } else {
                Array[i][j] = '|';
            }
        }
    }

    // Виведення масиву
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", Array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;

    // Отримання розміру масиву від користувача
    printf("Введіть розмір масиву (N): ");
    scanf("%d", &N);

    // Перевірка на коректність введеного значення
    if (N <= 0) {
        printf("Розмір масиву повинен бути більше нуля.\n");
        return 1; // Завершити програму з помилкою
    }

    FillArray(N);
    return 0;
}
