#include "c_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_and_destroy() {
    c_list* list = create_list(2);
    assert(list);
    list->destroy(list);
}

void test_append_and_pop() {
    c_list* list = create_list(2);
    int val = 42;
    float val2 = 3.14;
    list->append(list, &val, int_type);
    list->append(list, &val2, float_type);
    assert(list->size == 2);
    list->pop(list);
    assert(list->size == 1);
    list->destroy(list);
}

void run_tests() {
    test_create_and_destroy();
    test_append_and_pop();
    printf("All tests passed!\n");
}

int main() {
    run_tests();
    return 0;
}
