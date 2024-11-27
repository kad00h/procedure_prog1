#include <stdio.h>
#include <math.h>

double NewtonRaphson(double number, double initial_guess, double tolerance, int max_iterations, int* iterations) {
    double guess = initial_guess;
    double next_guess;

    for (*iterations = 0; *iterations < max_iterations; (*iterations)++) {
        next_guess = guess - (guess * guess - number) / (2 * guess); // Формула методу Ньютона-Рафсона

        if (fabs(next_guess - guess) < tolerance) {
            return next_guess; // Якщо досягли заданої точності
        }

        guess = next_guess;
    }

    return guess; // Повертаємо останнє значення, якщо не досягли точності
}

int main() {
    double number, initial_guess, tolerance, sqrt_result;
    int max_iterations, iterations;

    // Введення числа для знаходження квадратного кореня
    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);

    if (number <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    // Введення початкового припущення
    printf("Enter the initial guess for the root: ");
    scanf("%lf", &initial_guess);

    if (initial_guess <= 0) {
        printf("Please enter a positive initial guess.\n");
        return 1;
    }

    // Введення точності (похибки)
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    if (tolerance <= 0) {
        printf("Please enter a positive tolerance.\n");
        return 1;
    }

    // Введення максимальної кількості ітерацій
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    if (max_iterations <= 0) {
        printf("Please enter a positive number of iterations.\n");
        return 1;
    }

    // Виконання методу Ньютона-Рафсона
    sqrt_result = NewtonRaphson(number, initial_guess, tolerance, max_iterations, &iterations);

    // Виведення результатів
    printf("Number of iterations: %d\n", iterations);
    printf("Approximate square root: %.6lf\n", sqrt_result);

    return 0;
}
