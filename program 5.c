#include <stdio.h>
#include <string.h>

// Function to derive strings based on the CFG
void derive_S(char* input, int index) {
    if (input[index] == '\0') {
        return; // End of string
    }

    if (input[index] == '0') {
        printf("S -> 0S0\n");
        input[index] = 'S';
        derive_S(input, index + 1);
        input[index] = '0';
    } else {
        printf("S -> A\n");
        input[index] = 'A';
        derive_A(input, index);
    }
}

// Function to derive strings based on the CFG
void derive_A(char* input, int index) {
    if (input[index] == '\0') {
        return; // End of string
    }

    if (input[index] == '1') {
        printf("A -> 1A\n");
        input[index] = 'A';
        derive_A(input, index + 1);
        input[index] = '1';
    } else {
        printf("A -> e\n");
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

    if (belongs_to_cfg(input))
	 {
        printf("String belongs to the CFG language.\n");
    } else {
        printf("String does not belong to the CFG language.\n");
    }

    return 0;
}

