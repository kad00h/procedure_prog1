#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
    int num_chars;
    int key;

    srand((unsigned int) time(NULL));

    printf("Enter the number of characters to encrypt: ");
    if (scanf("%d", &num_chars) != 1 || num_chars <= 0) {
        printf("Invalid number of characters. Program exiting.\n");
        return 1;
    }

    key = (rand() % 513) - 256;
    printf("Generated encryption key: %d\n", key);

    for (int i = 0; i < num_chars; i++) {
        char input_char;

        printf("Enter character %d: ", i + 1);
        scanf(" %c", &input_char);

        if (!isalpha(input_char)) {
            printf("Invalid input. Please enter a letter.\n");
            i--;  
            continue;
        }

        input_char = tolower(input_char);

        char encrypted_char = ((input_char - 'a' + key) % 26 + 26) % 26 + 'a';

        printf("Encrypted character: %c\n", encrypted_char);
    }

    return 0;
}
