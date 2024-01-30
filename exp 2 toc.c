#include <stdio.h>
#include <stdbool.h>

// DFA transition function
int transition(int current_state, char input_symbol) {
    switch (current_state) {
        case 0:
            return (input_symbol == '0') ? 1 : 0;
        case 1:
            return (input_symbol == '1') ? 2 : 0;
        case 2:
            return 2; // Dead state, accepting state reached
        default:
            return -1; // Invalid state
    }
}

// DFA simulation function
bool simulate_dfa(const char *input_string) {
    int current_state = 0,i; // Initial state

    for ( i = 0; input_string[i] != '\0'; i++) {
        current_state = transition(current_state, input_string[i]);

        if (current_state == -1) {
            printf("Invalid state. Exiting.\n");
            return false;
        }
    }

    // Check if the final state is an accepting state
    return current_state == 2;
}

int main() {
    char input_string[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Simulate DFA and check acceptance
    if (simulate_dfa(input_string)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

