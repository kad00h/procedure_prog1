#include "c_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void resize_list(c_list* list);

// Ініціалізація нового списку
c_list* create_list(size_t initial_capacity) {
    c_list* list = malloc(sizeof(c_list));
    if (!list) return NULL;
    list->items = malloc(initial_capacity * sizeof(void*));
    list->types = malloc(initial_capacity * sizeof(list_data_type));
    list->size = 0;
    list->capacity = initial_capacity;
    list->append = append;
    list->pop = pop;
    list->destroy = destroy;
    list->print = print;
    list->remove_item = remove_item;
    list->sort = sort;
    return list;
}

// Додавання елемента
void append(c_list* list, void* item, list_data_type type) {
    if (list->size >= list->capacity) {
        resize_list(list);
    }
    list->items[list->size] = item;
    list->types[list->size] = type;
    list->size++;
}

// Видалення останнього елемента
void pop(c_list* list) {
    if (list->size == 0) return;
    if (list->types[list->size - 1] == string_type) {
        free(list->items[list->size - 1]);
    }
    list->size--;
}

// Видалення всіх елементів і звільнення пам'яті
void destroy(c_list* list) {
    for (size_t i = 0; i < list->size; i++) {
        if (list->types[i] == string_type) {
            free(list->items[i]);
        }
    }
    free(list->items);
    free(list->types);
    free(list);
}

// Вивід списку
void print(const c_list* list) {
    for (size_t i = 0; i < list->size; i++) {
        switch (list->types[i]) {
            case int_type:
                printf("%d ", *(int*)list->items[i]);
                break;
            case float_type:
                printf("%.2f ", *(float*)list->items[i]);
                break;
            case string_type:
                printf("%s ", (char*)list->items[i]);
                break;
        }
    }
    printf("\n");
}

// Видалення конкретного елемента
void remove_item(c_list* list, void* item, list_data_type type) {
    for (size_t i = 0; i < list->size; i++) {
        if (list->types[i] == type) {
            if ((type == int_type && *(int*)list->items[i] == *(int*)item) ||
                (type == float_type && *(float*)list->items[i] == *(float*)item) ||
                (type == string_type && strcmp((char*)list->items[i], (char*)item) == 0)) {
                free(list->items[i]);
                for (size_t j = i; j < list->size - 1; j++) {
                    list->items[j] = list->items[j + 1];
                    list->types[j] = list->types[j + 1];
                }
                list->size--;
                break;
            }
        }
    }
}

// Сортування списку (приклад: сортування чисел)
void sort(c_list* list) {
    // Реалізація сортування для чисел (за потреби додається порівняння для інших типів)
}

// Допоміжна функція для збільшення розміру списку
static void resize_list(c_list* list) {
    list->capacity *= 2;
    list->items = realloc(list->items, list->capacity * sizeof(void*));
    list->types = realloc(list->types, list->capacity * sizeof(list_data_type));
}
