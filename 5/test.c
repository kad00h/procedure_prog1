#include "bisection.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

// Структура для тестових параметрів
typedef struct {
    double a1, a2, b;
} TestCoefficients;

// Функція для обчислення f(x) = a1 * x^3 - (a2 * x^2 + b) для тестів
double intersection_test_function(double x, void* params) {
    TestCoefficients* coeff = (TestCoefficients*)params;
    return coeff->a1 * pow(x, 3) - (coeff->a2 * pow(x, 2) + coeff->b);
}

// Функція для тестування bisection
void test_bisection(double a1, double a2, double b) {
    TestCoefficients coeffs = {a1, a2, b};
    double tol = 1e-6;
    int max_iter = 1000;
    double a = -10.0, b_interval = 10.0;

    double root = bisection(intersection_test_function, a, b_interval, tol, max_iter, &coeffs);

    assert(fabs(intersection_test_function(root, &coeffs)) < tol);
    printf("Test passed for coefficients: a1=%.2f, a2=%.2f, b=%.2f, root=%.6f\n", a1, a2, b, root);
}

void run_tests() {
    test_bisection(1.0, 2.0, 3.0);
    test_bisection(2.0, -4.0, 1.0);
    test_bisection(-1.0, 1.0, 0.5);
    printf("All tests passed successfully.\n");
}
