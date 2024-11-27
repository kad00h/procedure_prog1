#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Необхідна бібліотека для strcmp

// Функція для виведення двійкового представлення числа
void print_binary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Пробіл кожні 8 біт для зручності читання
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    unsigned int value, key, encrypted, decrypted;
    int verbose = 0;

    // Перевірка наявності параметра для режиму "verbose"
    if (argc > 1 && strcmp(argv[1], "-v") == 0) {
        verbose = 1;
    }

    // Запит введення числа
    printf("Enter a value: ");
    if (scanf("%u", &value) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    // Запит введення ключа
    printf("Enter a key (number for XOR): ");
    if (scanf("%u", &key) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    // Вивід початкового значення
    printf("Original value (Decimal): %u\n", value);
    if (verbose) {
        printf("Binary: ");
        print_binary(value);
    }

    // Шифрування числа за допомогою XOR
    encrypted = value ^ key;
    printf("Encrypted value (Decimal): %u\n", encrypted);
    if (verbose) {
        printf("Binary: ");
        print_binary(encrypted);
    }

    // Розшифрування числа за допомогою XOR
    decrypted = encrypted ^ key;
    printf("Decrypted value (Original): %u\n", decrypted);
    if (verbose) {
        printf("Binary: ");
        print_binary(decrypted);
    }

    return 0;
}
