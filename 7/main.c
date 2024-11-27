#include <stdio.h>
#include <stdlib.h>
#include "c_list.h"

int main() {
    int size = 0;
    list_data_type types[100]; 
    void** list = create();
    if (!list) {
        printf("Failed to create list.\n");
        return 1;
    }

    int int_value = -6;
    types[size] = int_type;
    list = append(list, &size, &int_value, int_type);

    float float_value = 0.1;
    types[size] = float_type;
    list = append(list, &size, &float_value, float_type);

    char* string_value = "string_type";
    types[size] = string_type;
    list = append(list, &size, string_value, string_type);

    printf("Original list:\n");
    print((const void**)list, size, types);

    list = pop(list, &size);
    printf("List after pop:\n");
    print((const void**)list, size, types);

    destroy(list, size);
    return 0;
}
