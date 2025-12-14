//check if a string is palindrome using Stacks

#include <stdio.h>
#include <string.h>
#define MAX 20

int top = -1;
char stack[MAX];

// Function to push a character onto the stack
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
    }
}

// Function to pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';  // return null char if empty
    } else {
        return stack[top--];
    }
}

int main() {
    char str[20], revstr[20];
    int n, i;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    // Push all characters of the string
    for (i = 0; i < n; i++) {
        push(str[i]);
    }

    // Pop characters to form reversed string
    for (i = 0; i < n; i++) {
        revstr[i] = pop();
    }
    revstr[i] = '\0';  // null terminate

    printf("Reverse string: %s\n", revstr);

    // Check palindrome
    if (strcmp(str, revstr) == 0) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}
