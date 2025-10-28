// Implement a circular singly linked list with operations: insert at end, delete by key, and display nodes. 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;
NODE* insertend(NODE *, int);
NODE* deleteByKey(NODE *, int);
void display(NODE *);

int main() 
{
    NODE *start = NULL;
    int choice, num, key;

    while (1) {
        printf("\n--- Circular Singly Linked List ---\n");
        printf("1. Insert at end\n2. Delete by key\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d\n", &choice);

        switch(choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                start = insertend(start, num);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                start = deleteByKey(start, key);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to insert a node at the end
NODE* insertend(NODE *start, int n) 
{ 
    NODE *new_node, *ptr; 
    new_node = (NODE *) malloc(sizeof(NODE));  
    new_node->data = n; 

    if(start == NULL) {            
        start = new_node; 
        start->next = start; 
    } 
    else { 
        ptr = start;   
        while(ptr->next != start) { 
            ptr = ptr->next; 
        } 
        ptr->next = new_node;
        new_node->next = start; 
    } 
    return start; 
}

// Function to delete a node by key
NODE* deleteByKey(NODE *start, int key)
{
    NODE *curr = start, *prev = NULL;

    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    // If the list has only one node
    if (curr->next == start && curr->data == key) {
        free(curr);
        start = NULL;
        return start;
    }

    // If key is at the start node
    if (curr->data == key) {
        while (curr->next != start)
            curr = curr->next; // move to last node
        curr->next = start->next;
        NODE *temp = start;
        start = start->next;
        free(temp);
        return start;
    }

    // Otherwise, search for the key
    prev = start;
    curr = start->next;
    while (curr != start && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == start) {
        printf("Key %d not found.\n", key);
        return start;
    }

    prev->next = curr->next;
    free(curr);
    return start;
}

// Function to display the circular list
void display(NODE *start) 
{ 
    NODE *ptr; 
    ptr = start; 

    if (ptr == NULL) {          
        printf("List is empty\n");  
        return;   
    } 

    printf("The list data are:\n"); 
    do { 
        printf("%d ", ptr->data); 
        ptr = ptr->next; 
    } while(ptr != start);
    printf("\n");
}
