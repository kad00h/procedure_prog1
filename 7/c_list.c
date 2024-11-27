#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_list.h"

#define INITIAL_CAPACITY 4

static void** list = NULL;
static int capacity = INITIAL_CAPACITY;

void** create() {
    list = (void**)malloc(INITIAL_CAPACITY * sizeof(void*));
    if (!list) return NULL;
    return list;
}

void** append(void** ptr, int* size, void* item, list_data_type type) {
    if (*size == capacity) {
        capacity *= 2;
        ptr = realloc(ptr, capacity * sizeof(void*));
        if (!ptr) return NULL;
    }
    if (type == string_type) {
        char* str = (char*)malloc(strlen((char*)item) + 1);
        strcpy(str, (char*)item);
        ptr[*size] = str;
    } else {
        size_t item_size = (type == int_type) ? sizeof(int) : sizeof(float);
        ptr[*size] = malloc(item_size);
        memcpy(ptr[*size], item, item_size);
    }
    (*size)++;
    return ptr;
}

void** pop(void** ptr, int* size) {
    if (*size == 0) return ptr;
    free(ptr[(*size) - 1]);
    ptr[(*size) - 1] = NULL;
    (*size)--;
    return ptr;
}

void print(const void** ptr, int size, list_data_type* types) {
    for (int i = 0; i < size; i++) {
        if (ptr[i] == NULL) continue;

        switch (types[i]) {
            case int_type:
                printf("%d ", *(int*)ptr[i]);
                break;
            case float_type:
                printf("%f ", *(float*)ptr[i]);
                break;
            case string_type:
                printf("%s ", (char*)ptr[i]);
                break;
            default:
                printf("Unknown type ");
        }
    }
    printf("\n");
}

void destroy(void** ptr, int size) {
    for (int i = 0; i < size; i++) {
        free(ptr[i]);
    }
    free(ptr);
}
