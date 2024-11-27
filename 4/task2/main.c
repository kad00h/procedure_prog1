#include <stdio.h>
#include <string.h>

int FindSubstring(const char* original, const char* substring) {
    int original_len = 0, substring_len = 0;

    // Розрахунок довжини рядків
    while (original[original_len] != '\0') original_len++;
    while (substring[substring_len] != '\0') substring_len++;

    // Якщо довжина підрядка більша за довжину рядка
    if (substring_len > original_len) return -1;

    // Пошук підрядка вручну
    for (int i = 0; i <= original_len - substring_len; i++) {
        int j;
        for (j = 0; j < substring_len; j++) {
            if (original[i + j] != substring[j]) {
                break;
            }
        }
        // Якщо всі символи збіглися
        if (j == substring_len) {
            return i;
        }
    }
    return -1; // Підрядок не знайдено
}

int main() {
    char original[100], substring[100];

    // Введення рядків
    printf("Enter original string: ");
    fgets(original, sizeof(original), stdin);
    // Видалення символу нового рядка (\n), якщо він є
    original[strcspn(original, "\n")] = '\0';

    printf("Enter substring: ");
    fgets(substring, sizeof(substring), stdin);
    // Видалення символу нового рядка (\n), якщо він є
    substring[strcspn(substring, "\n")] = '\0';

    // Виклик функції пошуку підрядка
    int index = FindSubstring(original, substring);

    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring found at index: -1\n");
    }

    return 0;
}
