// Extend the program to reverse the linked list elements. 

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} NODE;

// Function to insert a node at the end
NODE* insertEnd(NODE* start, int value) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = value;
    new_node->next = NULL;

    if (start == NULL) {
        return new_node;
    }

    NODE* ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}

// Function to display the list
void display(NODE* start) {
    NODE* ptr = start;
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to reverse the linked list
NODE* reverse(NODE* start) {
    NODE *prev, *temp, *ptr;

    if (start == NULL) {
        printf("List Empty\n");
        return start;
    }

    if (start->next == NULL) {
        printf("Only one Node %d\n", start->data);
        return start;
    }
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

// Main function
int main() {
    NODE* start = NULL;

    // Create sample list: 10 -> 20 -> 30 -> 40
    start = insertEnd(start, 10);
    start = insertEnd(start, 20);
    start = insertEnd(start, 30);
    start = insertEnd(start, 40);

    printf("Original ");
    display(start);

    start = reverse(start);

    printf("Reversed ");
    display(start);

    return 0;
}
