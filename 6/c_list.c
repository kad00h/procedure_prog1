#include "c_list.h"
#include <stdio.h>

list_data_type list_types[CAPACITY];

int append_list_item(void* list[], int size, void* item, list_data_type type) {
    if (size >= CAPACITY) {
        return -1; // Список переповнений
    }
    list[size] = item;
    list_types[size] = type;
    return size + 1;
}

void print_list(const void* list[], int size) {
    for (int i = 0; i < size; i++) {
        if (list_types[i] == int_type) {
            printf("%d ", *(int*)list[i]);
        } else if (list_types[i] == float_type) {
            printf("%f ", *(float*)list[i]);
        } else if (list_types[i] == string_type) {
            printf("%s ", (char*)list[i]);
        }
    }
    printf("\n");
}
