// Implement a circular queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
typedef struct node NODE;

void insertrear(int);
void deletefront();
void display();

NODE *front = NULL, *rear = NULL;

int main() {
    int num, choice;
    while(1) {
        printf("\n1. Insert at rear\n2. Delete at front\n3. Display\n4. Stop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &num);
                insertrear(num);
                break;

            case 2:
                deletefront();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

void insertrear(int n) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->num = n;
    newnode->next = NULL;

    // When queue is empty
    if(front == NULL && rear==NULL) {
        front = rear = newnode;
        newnode->next = front; // circular link
        return;
    }

    // Insert at rear
    rear->next = newnode;
    newnode->next = front;
    rear = newnode;
}

void deletefront() {

    if(front == NULL && rear==NULL) {
        printf("Queue Empty\n");
        return;
    }


    // Only one node
    if(front->next == front) {
        printf("Item deleted: %d\n", front->num);
        free(front);
        front = rear = NULL;
        return;
    }

    // More than one node
    NODE *temp = front;
    printf("Item deleted: %d\n", front->num);
    front = front->next;
    rear->next = front;
    free(temp);
    return;
}

void display() {
    if(front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    NODE *temp = front;
    printf("Queue elements: ");

    do {
        printf("%d ", temp->num);
        temp = temp->next;
    } while(temp != front);

    printf("\n");
}
