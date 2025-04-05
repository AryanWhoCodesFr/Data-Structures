#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);  // More robust error handling
    }
}

int evaluatePostfix(char *expr) {
    char *token = strtok(expr, " ");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Token is an operand (handle negative too)
            push(atoi(token));
        } else if (strlen(token) == 1) {
            // Operator
            int b = pop();
            int a = pop();

            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(a / b); 
                    break;
                default:
                    printf("Invalid Operator: %s\n", token);
                    exit(EXIT_FAILURE);
            }
        } else {
            printf("Invalid Token: %s\n", token);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }
    
    return pop();  // Final result
}

int main() {
    char expr[MAX];

    printf("Enter postfix expression (space-separated): ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';  // Remove newline

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}
