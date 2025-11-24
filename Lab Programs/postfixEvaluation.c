#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>   

#define MAX 100
int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack[++top] = x;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i;
    char ch;
    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        
        if (isdigit(ch)) {    // If operand, push to stack
            push(ch - '0');  // convert char digit to int
        }
        // If operator, pop two operands and apply
        else if(ch=='+'|| ch=='-'|| ch=='*'|| ch=='/' || ch=='%') {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '%': push(val1 % val2); break;
            }
        }
        else if(ch==' '){
            continue;
        }
        else{
            printf("Invalid character: %c\n",ch);
            exit(1);
        }
    }
    return pop();  // final result
}

int main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}
