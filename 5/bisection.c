#include <stdio.h>
#include <math.h>
#include "bisection.h"

// Bisection method to find root
double bisection(double (*func)(double, void*), double a, double b, double tol, int max_iter, void* params) {
    double mid;
    for (int i = 0; i < max_iter; i++) {
        mid = (a + b) / 2.0;
        if (fabs(func(mid, params)) < tol || (b - a) / 2.0 < tol) {
            return mid;
        }
        if (func(a, params) * func(mid, params) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
    return mid; // Returns the midpoint as the approximation
}
