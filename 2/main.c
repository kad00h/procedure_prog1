#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// Function to print binary representation of a number
void print_binary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Add a space every 8 bits for readability
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    unsigned int value, key, encrypted, decrypted;
    int verbose = 0;

    // Check if verbose mode is enabled
    if (argc > 1 && strcmp(argv[1], "-v") == 0) {
        verbose = 1;
    }

    // Prompt user for input
    printf("Enter a value: ");
    if (scanf("%u", &value) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    printf("Enter a key (number for XOR): ");
    if (scanf("%u", &key) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    // Display original value
    printf("Original value (Decimal): %u\n", value);
    if (verbose) {
        printf("Binary: ");
        print_binary(value);
    }

    // Encrypt the value using XOR
    encrypted = value ^ key;
    printf("Encrypted value (Decimal): %u\n", encrypted);
    if (verbose) {
        printf("Binary: ");
        print_binary(encrypted);
    }

    // Decrypt the value back using XOR
    decrypted = encrypted ^ key;
    printf("Decrypted value (Original): %u\n", decrypted);
    if (verbose) {
        printf("Binary: ");
        print_binary(decrypted);
    }

    return 0;
}
