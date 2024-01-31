#include <stdio.h>
#include <string.h>

// NFA transition function
int nfa_transition(int current_state, char input) {
    switch (current_state) {
        case 0:
            if (input == 'o') {
                return 1;  // Move to state 1 if 'o' is encountered
            }
            break;
        case 1:
            if (input == '1') {
                return 2;  // Move to state 2 if '1' is encountered
            } else if (input == 'o') {
                return 1;  // Stay in state 1 if 'o' is encountered
            }
            break;
        default:
            break;
    }
    return -1; // Invalid transition or no transition
}

// NFA simulation function
int simulate_nfa(const char* input) {
    int current_state = 0,i; // Initial state

    for (i = 0; i < strlen(input); i++) {
        char symbol = input[i];
        int result = nfa_transition(current_state, symbol);

        if (result == -1) {
            return 0; // String is not accepted by NFA, it is rejected
        }

        current_state = result;
    }

    // Check if the final state is the accepting state (state 2)
    return (current_state == 2);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_nfa(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

