#include <stdio.h>
#include <string.h>

// Function to derive strings based on the CFG for A
void derive_A(char* input, int index) {
    if (input[index] == '\0') {
        return; // End of string
    }

    if (input[index] == '0' || input[index] == '1') {
        printf("A -> %cA\n", input[index]);
        input[index] = 'A';
        derive_A(input, index + 1);
    } else {
        printf("A -> e\n");
    }
}

// Function to derive strings based on the CFG for S
void derive_S(char* input, int index) {
    if (input[index] == '\0') {
        return; // End of string
    }

    if (input[index] == 'A' && input[index + 1] == '1' && input[index + 2] == '0' && input[index + 3] == '1' && input[index + 4] == 'A') {
        printf("S -> A101A\n");
        input[index] = 'S';
        derive_A(input, index + 1);
        input[index + 1] = '0';
        input[index + 2] = '1';
        input[index + 3] = 'A';
        derive_A(input, index + 4);
    } else {
        printf("S -> e\n");
    }
}

// Function to check if the string belongs to the CFG language
int belongs_to_cfg(char* input) {
    derive_S(input, 0);

    return (strcmp(input, "") == 0); // Check if the derived string is empty
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (belongs_to_cfg(input)) {
        printf("String belongs to the CFG language.\n");
    } else {
        printf("String does not belong to the CFG language.\n");
    }

    return 0;
}

