// Extend the program to reverse the linked list elements. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node NODE;

NODE* reverse(NODE *start);
void display(NODE* start);
NODE* createList(NODE* start);

int main() {
    NODE *start = NULL;

    start = createList(start);

    printf("\nOriginal linked list:\n");
    display(start);

    start = reverse(start);

    printf("\nReversed linked list:\n");
    display(start);

    return 0;
}

NODE* createList(NODE* start) {
    NODE *newNode, *ptr;
    int n, val;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &val);

        newNode = (NODE*) malloc(sizeof(NODE));
        newNode->data = val;
        newNode->next = NULL;

        if(start == NULL)
            start = newNode;
        else {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
        }
    }
    return start;
}

NODE* reverse(NODE *start) {
    NODE *prev, *temp, *ptr;
    if (start == NULL) {
        printf("List Empty\n");
        return start;
    }
    else if (start->next == NULL) {
        printf("Only one Node %d\n", start->data);
        return start;
    } else {
        prev = NULL;
        ptr = start;
        while (ptr != NULL) {
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        start = prev;
        return start;
    }
}

void display(NODE* start) {
    NODE* ptr;
    if (start == NULL) {
        printf("List is empty.\n");
    } else {
        ptr = start;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}


/*
Enter the number of nodes: 3
Enter data for node 1: 7
Enter data for node 2: 5
Enter data for node 3: 6

Original linked list:
7 -> 5 -> 6 -> NULL

Reversed linked list:
6 -> 5 -> 7 -> NULL
*/