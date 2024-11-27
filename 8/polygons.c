#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для зберігання координат точки
typedef struct {
    int x, y;
} point_t;

// Структура для багатокутника
typedef struct {
    char* name;        // Назва багатокутника
    int num_points;    // Кількість точок
    point_t* points;   // Масив точок
} polygon_t;

// Функція для читання багатокутників з файлу
polygon_t* read_polygons(const char* filename, int* polygon_count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Не вдалося відкрити файл");
        exit(EXIT_FAILURE);
    }

    polygon_t* polygons = NULL;
    *polygon_count = 0;

    while (!feof(file)) {
        polygon_t polygon;
        char buffer[100];

        // Читання назви багатокутника
        if (!fgets(buffer, sizeof(buffer), file)) break;
        buffer[strcspn(buffer, "\n")] = '\0';
        polygon.name = strdup(buffer);

        // Читання кількості точок
        if (fscanf(file, "%d\n", &polygon.num_points) != 1) {
            fprintf(stderr, "Помилка читання кількості точок\n");
            break;
        }

        // Виділення пам'яті для точок
        polygon.points = malloc(polygon.num_points * sizeof(point_t));
        if (!polygon.points) {
            perror("Помилка виділення пам'яті для точок");
            break;
        }

        // Читання точок
        for (int i = 0; i < polygon.num_points; i++) {
            if (fscanf(file, "%d %d\n", &polygon.points[i].x, &polygon.points[i].y) != 2) {
                fprintf(stderr, "Помилка читання координат точки\n");
                break;
            }
        }

        // Додавання багатокутника до масиву
        polygons = realloc(polygons, (*polygon_count + 1) * sizeof(polygon_t));
        polygons[*polygon_count] = polygon;
        (*polygon_count)++;
    }

    fclose(file);
    return polygons;
}

// Функція для друку багатокутників
void print_polygons(polygon_t* polygons, int count) {
    for (int i = 0; i < count; i++) {
        printf("Polygon: %s\n", polygons[i].name);
        printf("Points: ");
        for (int j = 0; j < polygons[i].num_points; j++) {
            printf("(%d, %d)", polygons[i].points[j].x, polygons[i].points[j].y);
            if (j < polygons[i].num_points - 1) printf(", ");
        }
        printf("\n");
    }
}

// Функція для звільнення пам'яті
void free_polygons(polygon_t* polygons, int count) {
    for (int i = 0; i < count; i++) {
        free(polygons[i].name);
        free(polygons[i].points);
    }
    free(polygons);
}

int main() {
    const char* filename = "polygons.txt";
    int polygon_count;

    polygon_t* polygons = read_polygons(filename, &polygon_count);
    print_polygons(polygons, polygon_count);
    free_polygons(polygons, polygon_count);

    return 0;
}
