#ifndef C_LIST_H
#define C_LIST_H

#include <stddef.h>

// Enum для ідентифікації типу даних (int, float, string)
typedef enum {
    int_type,
    float_type,
    string_type
} list_data_type;

// Основна структура c_list
typedef struct c_list {
    void** items;               // Масив вказівників на елементи
    list_data_type* types;      // Масив типів даних для кожного елемента
    size_t size;                // Поточна кількість елементів
    size_t capacity;            // Поточна ємність масиву
    void (*append)(struct c_list* list, void* item, list_data_type type); // Додавання елемента
    void (*pop)(struct c_list* list);                                     // Видалення останнього елемента
    void (*destroy)(struct c_list* list);                                 // Звільнення пам'яті
    void (*print)(const struct c_list* list);                             // Вивід списку
    void (*remove_item)(struct c_list* list, void* item, list_data_type type); // Видалення елемента
    void (*sort)(struct c_list* list);                                    // Сортування
} c_list;

// Прототипи функцій
c_list* create_list(size_t initial_capacity);
void append(c_list* list, void* item, list_data_type type);
void pop(c_list* list);
void destroy(c_list* list);
void print(const c_list* list);
void remove_item(c_list* list, void* item, list_data_type type);
void sort(c_list* list);

#endif // C_LIST_H
