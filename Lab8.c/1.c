#include <stdio.h>
#include <stdlib.h>

int top = -1;
const int n = 8;
int arr[8];

void push(int x) {
    if (top < n - 1) {
        top++;
        arr[top] = x;
        printf("Pushed %d onto the stack.\n", x);
    } else {
        printf("Stack overflow! Cannot push %d\n", x);
    }
}

void pop() {
    if (top != -1) {
        printf("Popped %d from the stack.\n", arr[top]);
        top--;
    } else {
        printf("There is no element to remove (Stack Underflow).\n");
    }
}

void display() {
    if (top == -1) {
        printf("There is no element in the stack.\n");
    } else {
        printf("Current Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int m = 1;
    while (m) {
        int option;
        printf("\n--- Stack Menu ---\n");
        printf("0 - Stop the program\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Display\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int k;
                printf("Enter the number to be pushed onto the stack: ");
                scanf("%d", &k);
                push(k);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                m = 0;
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    }
    return 0;
}
