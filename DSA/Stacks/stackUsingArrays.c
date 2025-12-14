//Implementation of stack using arrays:
#include<stdio.h>
#include<stdlib.h>

int MAX, stack[20];
int push(int, int);
int pop(int);
void peek(int);
void display(int);

int main(){
    int top=-1, choice, num;
    printf("Enter the size of the stack: ");
    scanf("%d",&MAX);
    printf("----Stack Operations----\n1.PUSH an element\n2.POP an element\n3.PEEK an element\n4.Display Stack\n5.Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to push: ");
                    scanf("%d",&num); top=push(top, num);
                    break;
            case 2: top=pop(top);
            break;
            case 3: peek(top);
                    break;
            case 4: display(top);
            break;
            case 5: printf("Exited Successfully!\n"); exit(0);break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

int push(int top, int num){
    if(top>=MAX-1){
        printf("Overflow\n");
    } else{
        top++;
        stack[top]=num;
    }
    return top;
}

int pop(int top){
    if(top==-1){
        printf("Underflow\n");
    }else{
        printf("Popped element is: %d\n",stack[top]);
        top--;
    }
    return top;
}

void peek(int top){
    if(top==-1){
        printf("Stack is empty\n");
    }else{
        printf("The topmost element is: %d\n",stack[top]);
    }
}
void display(int top){
    int i;
    if(top==-1){
        printf("Underflow\n");
    }else{
        printf("The stack data are: ");
        for(i=top; i>=0; i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}