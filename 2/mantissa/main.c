#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef union {
    float value;
    struct {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } ieee;
} FloatUnion;

int main() {
    float input;
    printf("Enter a floating-point number: ");
    scanf("%f", &input);

    // Use a union to interpret the float in IEEE 754 format
    FloatUnion num;
    num.value = input;

    // Extract sign, exponent, and mantissa
    int sign = num.ieee.sign ? -1 : 1;
    int exponent = num.ieee.exponent - 127; // Exponent bias for single precision
    float mantissa = 1.0 + (num.ieee.mantissa / (float)(1 << 23)); // Normalized mantissa

    // Handle subnormal numbers
    if (num.ieee.exponent == 0) {
        mantissa = num.ieee.mantissa / (float)(1 << 23);
        exponent = -126; // Subnormal exponent
    }

    // Reconstruct the number
    float reconstructed = sign * mantissa * powf(2, exponent);

    // Print results
    printf("Sign bit: %c\n", sign > 0 ? '+' : '-');
    printf("Mantissa value: %.6f\n", mantissa - 1.0);
    printf("Exponent value: %d\n", exponent);
    printf("Reconstructed value: (%c1.0 + %.6f) * 2**%d = %.6f\n", 
           sign > 0 ? '+' : '-', mantissa - 1.0, exponent, reconstructed);

    return 0;
}
