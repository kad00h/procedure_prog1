#include <stdio.h>
#include <math.h>
#include "bisection.h"

// Структура для параметрів функції
typedef struct {
    double a1, a2, b;
} Coefficients;

// Функція для обчислення f(x) = a1 * x^3 - (a2 * x^2 + b)
double intersection_function(double x, void* params) {
    Coefficients* coeff = (Coefficients*)params;
    return coeff->a1 * pow(x, 3) - (coeff->a2 * pow(x, 2) + coeff->b);
}

int main() {
    Coefficients coeffs;
    double a, b_interval, tol;
    int max_iter;

    // Введення коефіцієнтів
    printf("Enter the coefficients a1, a2, and b (space-separated): ");
    if (scanf("%lf %lf %lf", &coeffs.a1, &coeffs.a2, &coeffs.b) != 3) {
        printf("Invalid input. Please provide three numbers.\n");
        return 1;
    }

    // Введення інтервалу
    printf("Enter the interval [a, b] (space-separated): ");
    if (scanf("%lf %lf", &a, &b_interval) != 2) {
        printf("Invalid input. Please provide two numbers.\n");
        return 1;
    }

    // Введення точності
    printf("Enter the tolerance: ");
    if (scanf("%lf", &tol) != 1 || tol <= 0) {
        printf("Invalid input. Tolerance must be a positive number.\n");
        return 1;
    }

    // Введення максимальної кількості ітерацій
    printf("Enter the maximum iterations: ");
    if (scanf("%d", &max_iter) != 1 || max_iter <= 0) {
        printf("Invalid input. Maximum iterations must be a positive integer.\n");
        return 1;
    }

    // Виклик методу бісекції
    double root = bisection(intersection_function, a, b_interval, tol, max_iter, &coeffs);

    // Виведення результату
    printf("Intersection found at x = %.6lf\n", root);

    return 0;
}
