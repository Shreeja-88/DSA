//Implementation of stack using Linked List:
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE* push(NODE*, int);
NODE* pop(NODE*);
void peek(NODE*);
void display(NODE*);

int main(){
    NODE* top=NULL;
    int choice, num;
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

NODE* push(NODE *top, int n){
    NODE *nn= (NODE*)malloc(sizeof(NODE));
    nn->data = n; nn->next=top;
    top=nn; return top;
}

NODE* pop(NODE*top){
    NODE* ptr;
    if(top==NULL){
        printf("Stack is empty\n"); return top;
    }else{
        ptr=top;
        top=top->next;
        printf("Popped data: %d\n",ptr->data);
        free(ptr);
        return top;
    }
}

void peek(NODE* top){
    if(top == NULL){
        printf("Stack is empty\n");
    } else {
        printf("The topmost element is: %d\n", top->data);
    }
}

void display(NODE*top){
    NODE* ptr=top;
    if(ptr==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("The stack data: ");
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}