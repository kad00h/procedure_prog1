#ifndef BISECTION_H
#define BISECTION_H

// bisection
double bisection(double (*func)(double, void*), double a, double b, double tol, int max_iter, void* params);

#endif
