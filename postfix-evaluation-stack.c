#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push value onto stack
void push(int value) {
    if (top >= SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop value from stack
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {
        // If token is a number (handle negative or multi-digit)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else if (strlen(token) == 1) {
            // It's an operator
            int b = pop();
            int a = pop();
            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push((int)pow(a, b)); break;
                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);
            }
        } else {
            printf("Invalid token: %s\n", token);
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    return pop(); // Final result
}

int main() {
    char expression[SIZE];

    printf("Enter a postfix expression (space-separated):\n");
    fgets(expression, SIZE, stdin);

    // Remove trailing newline if present
    expression[strcspn(expression, "\n")] = 0;

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
