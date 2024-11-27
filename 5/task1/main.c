#include <stdio.h>
#include <math.h>

double BabylonianMethod(double number, double tolerance, int* iterations) {
    double guess = number / 2.0; // Початкове припущення
    double previous_guess;
    *iterations = 0;

    do {
        previous_guess = guess;
        guess = (guess + number / guess) / 2.0; // Формула Герона
        (*iterations)++;
    } while (fabs(guess - previous_guess) > tolerance); // Перевірка точності

    return guess;
}

int main() {
    double number, tolerance, sqrt_result;
    int iterations;

    // Введення числа та допустимої похибки
    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);

    if (number <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    if (tolerance <= 0) {
        printf("Please enter a positive tolerance.\n");
        return 1;
    }

    // Обчислення квадратного кореня
    sqrt_result = BabylonianMethod(number, tolerance, &iterations);

    // Виведення результатів
    printf("Number of iterations: %d\n", iterations);
    printf("Approximate square root: %.6lf\n", sqrt_result);

    return 0;
}
