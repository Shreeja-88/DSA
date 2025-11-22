//Write a C program to convert an expression given in infix form to postfix using stack concept

#include <stdio.h>
#include <ctype.h>

void infixpostfix(char in[50]);
int precedence(char operator);
int isOperator(char ch);

int main() {
    char infix[50];
    printf("Enter the expression: ");
    scanf("%s", infix);
    infixpostfix(infix);
    return 0;
}

int isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;
    }
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixpostfix(char in[50]) {
    char stack[50], postfix[50];
    int top = -1, i, j;

    for (i = 0, j = 0; in[i] != '\0'; i++) {
        if (isalnum(in[i])) {
            // Operand goes directly to postfix
            postfix[j++] = in[i];
        } else if (in[i] == '(') {
            stack[++top] = in[i];
        } else if (in[i] == ')') {
            // Pop until '(' is found
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
                top--; // remove '('
            
        } else if (isOperator(in[i])) {
            // Pop operators of higher or equal precedence
            while (top > -1 && precedence(stack[top]) >= precedence(in[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = in[i];
        }
    }

    // Pop remaining operators
    while (top > -1) {
        if (stack[top] == '(') {
            printf("Invalid expression\n");
            return;
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    printf("The corresponding postfix expression is: %s\n", postfix);
}
