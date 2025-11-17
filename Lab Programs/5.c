/*
Write a program to design develop and implement a menu-driven program in c for the following operations on STACK of integers (Array Implementation of the stack with maximum size MAX=4).
1) Push an element on the stack 
2) Pop an element from the stack
3) Check overflow and underflow situations on the stack 
4) Display the contents of stack
5) Exit
Support the program with appropriate functions for each of the above operations. 
*/

#include<stdio.h>
#include<stdlib.h>
int MAX, stack[10];
int push(int, int);
int pop(int);
void display(int);

int main(){
    int top = -1, choice, num;
    printf("Enter the size of STACK: ");
    scanf("%d",&MAX);
    while(1){
        printf("1.Push\n2.POP\n3.Display\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &num);
                top = push(top, num);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("EXIT POINT\n");
                exit(0);
                break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

int push(int top, int num){
    if(top>=MAX-1){
        printf("OVERFLOW\n");
    } else{
        top++;
        stack[top]=num;
    }
    return top;
}

int pop(int top){
    if(top==-1){
        printf("Underflow\n");
    } else{
        printf("Popped element is %d \n", stack[top]);
        top--;
    }
    return top;
}

void display(int top){
    int i;
    if(top==-1){
        printf("Underflow\n");
    } else{
        printf("Stack Data: ");
        for(i=top; i>=0;i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}