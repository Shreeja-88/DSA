//given two singly linked list the task is to insert nodes of 2nd list to first list at alternating positions of the 1st list and leave the remaining nodes of the 2nd list if it's longer

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAlternate(struct Node* head1, struct Node** head2) {
    struct Node *curr1 = head1, *curr2 = *head2;
    struct Node *next1, *next2;

    while (curr1 != NULL && curr2 != NULL) {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }

    *head2 = curr2;   // leftover nodes of list2
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // List 1
    struct Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    // List 2
    struct Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(8);

    insertAlternate(head1, &head2);

    printf("After merging alternate:\nList 1: ");
    printList(head1);

    printf("Remaining List 2: ");
    printList(head2);

    return 0;
}
