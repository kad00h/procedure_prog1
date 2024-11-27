#include "c_list.h"
#include <stdio.h>

int main() {
    void* list[CAPACITY];
    int size = 0;

    int i = 42;
    float f = 3.14;
    char* s1 = "C programming";
    char* s2 = "Home task 6";

    size = append_list_item(list, size, &i, int_type);
    size = append_list_item(list, size, &f, float_type);
    size = append_list_item(list, size, s1, string_type);
    size = append_list_item(list, size, s2, string_type);

    print_list((const void**)list, size);

    return 0;
}
