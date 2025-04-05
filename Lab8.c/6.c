#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

void pop() {
    if (top != -1) {
        top--;
    } else {
        printf("Stack underflow\n");
    }
}

char topElement() {
    return (top != -1) ? stack[top] : '\0';
}

bool isBalanced(const char* expr) {
    top = -1;  // Reset stack for each new expression

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char t = topElement();
            if ((ch == ')' && t == '(') ||
                (ch == ']' && t == '[') ||
                (ch == '}' && t == '{')) {
                pop();
            } else {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char input[MAX];

    printf("Enter the parentheses expression: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline

    if (isBalanced(input)) {
        printf("YES, parentheses are balanced.\n");
    } else {
        printf("NO, parentheses are NOT balanced.\n");
    }

    return 0;
}
