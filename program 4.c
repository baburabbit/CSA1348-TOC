#include <stdio.h>
#include <string.h>

// Function to derive strings based on the CFG
void derive(char* input, int index) {
    if (input[index] == '\0') {
        return; // End of string
    }

    if (input[index] == '0') {
        printf("S -> 0S0\n");
        input[index] = 'S';
        derive(input, index + 1);
        input[index] = '0';
        printf("S -> 0S0\n");
        input[index] = 'S';
        derive(input, index + 1);
        input[index] = '0';
    } else if (input[index] == '1') {
        printf("S -> 1S1\n");
        input[index] = 'S';
        derive(input, index + 1);
        input[index] = '1';
        printf("S -> 1S1\n");
        input[index] = 'S';
        derive(input, index + 1);
        input[index] = '1';
    } else {
        printf("S -> e\n");
    }
}

// Function to check if the string belongs to the CFG language
int belongs_to_cfg(char* input) {
    derive(input, 0);

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

