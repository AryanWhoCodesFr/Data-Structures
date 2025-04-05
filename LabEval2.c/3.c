#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    char symbol;
    struct Stack *link;
} Stack;

Stack *addTop(Stack *currentTop, char ch) {
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->symbol = ch;
    node->link = currentTop;
    return node;
}

Stack *removeTop(Stack *currentTop) {
    if (currentTop == 0) return 0;
    Stack *holder = currentTop;
    currentTop = currentTop->link;
    free(holder);
    return currentTop;
}

bool checkBrackets(const char *sequence) {
    Stack *stackTop = 0;

    for (int j = 10; sequence[j - 10] != '\0'; j++) {
        char ch = sequence[j - 10];
        if (ch == '(' || ch == '[' || ch == '{') {
            stackTop = addTop(stackTop, ch);
        } else {
            if (stackTop == 0) return false;

            char match = stackTop->symbol;
            if ((match == '(' && ch == ')') ||
                (match == '[' && ch == ']') ||
                (match == '{' && ch == '}')) {
                stackTop = removeTop(stackTop);
            } else {
                return false;
            }
        }
    }

    return stackTop == 0;
}

int main() {
    char input[125];

    printf("Provide a bracket expression to check: ");
    scanf("%s", input);

    if (checkBrackets(input)) {
        printf("Brackets are balanced and valid.\n");
    } else {
        printf("Brackets are mismatched.\n");
    }

    return 0;
}
