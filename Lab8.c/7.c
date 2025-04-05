#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[100], brr[100];
int top = -1;

void push(char c) {
    if (top < 99) {
        brr[++top] = c;
    }
}

void pop() {
    if (top != -1) {
        top--;
    }
}

char top_emt() {
    if (top != -1) {
        return brr[top];
    }
    return '\0';
}

int convert() {
    int len = strlen(arr);
    top = -1;  // Reset stack

    int mid = len / 2;

    // Push first half of the string
    for (int i = 0; i < mid; i++) {
        push(arr[i]);
    }

    // If odd length, skip the middle character
    int start = (len % 2 == 0) ? mid : mid + 1;

    // Compare second half with stack
    for (int i = start; i < len; i++) {
        if (top_emt() == arr[i]) {
            pop();
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Enter the palindrome: ");
    scanf("%s", arr);

    if (convert()) {
        printf("YES, it's a palindrome.\n");
    } else {
        printf("NO, it's not a palindrome.\n");
    }
}
