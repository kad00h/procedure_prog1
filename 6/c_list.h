#ifndef C_LIST_H
#define C_LIST_H

#define CAPACITY 100

typedef enum {
    int_type,
    float_type,
    string_type
} list_data_type;

int append_list_item(void* list[], int size, void* item, list_data_type type);
void print_list(const void* list[], int size);

#endif // C_LIST_H
