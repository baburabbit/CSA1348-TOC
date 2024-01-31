#include <stdio.h>

// Function to find e-closure for a state in NFA
void epsilonClosure(int state, int nfa[][10], int n, int epsilon[]) {
    int stack[10], top = -1;
    int visited[10] = {0};

    printf("e-Closure(q%d): {q%d", state, state);

    stack[++top] = state;
    visited[state] = 1;

    while (top != -1) {
        int i,current_state = stack[top--];

        for (i = 0; i < n; i++) {
            if (nfa[current_state][i] == -1) {
                // e-move
                if (!visited[i]) {
                    printf(", q%d", i);
                    stack[++top] = i;
                    visited[i] = 1;
                }
            }
        }
    }

    printf("}\n");
}

int main() {
    int nfa[10][10], n, m;
    int epsilon[10] = {0};

    printf("Enter the number of states in NFA: ");
    scanf("%d", &n);

    printf("Enter the number of symbols in the alphabet (excluding e): ");
    scanf("%d", &m);
    int i,j;
    // Initialize NFA transitions with -1 (no transition)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            nfa[i][j] = -1;
        }
    }

    // Input NFA transitions
    printf("Enter NFA transitions (use -1 for no transition):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Transition for q%d on symbol %c: ", i, 'a' + j);
            scanf("%d", &nfa[i][j]);
        }
    }

    // Find e-closure for all states
    for (i = 0; i < n; i++) {
        epsilonClosure(i, nfa, n, epsilon);
    }

    return 0;
}

