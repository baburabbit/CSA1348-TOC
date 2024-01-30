#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isValidString(char* str);
bool matchS(char* str);
bool matchA(char* str);

int main() {
    char inputString[100];

    // Get user input
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Check if the input string is valid according to the CFG
    if (isValidString(inputString)) {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}

// Function to check if the string is valid according to the CFG
bool isValidString(char* str) {
    return matchS(str);
}

// Function to match the production rule S -> 0A1
bool matchS(char* str) {
    if (str[0] == '0') {
        str++;
        if (matchA(str)) {
            if (str[0] == '1') {
                return true;
            }
        }
    }
    return false;
}

// Function to match the production rule A -> 0A | 1A | e
bool matchA(char* str) {
    if (str[0] == '0') {
        str++;
        return matchA(str);
    } else if (str[0] == '1') {
        str++;
        return matchA(str);
    } else {
        // Empty string is also accepted for A -> e
        return true;
    }
}

