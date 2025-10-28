#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE* insertfrontend(NODE *, int);
NODE* insertend(NODE *, int);
NODE* deletefront(NODE *);
NODE* deleteend(NODE *);
void display(NODE *);

int main() 
{ 
    NODE *start = NULL; 
    int choice, num; 

    while (1) { 
        printf("\n--- Circular Singly Linked List Menu ---\n"); 
        printf("1. Insert at Front\n"); 
        printf("2. Insert at End\n"); 
        printf("3. Delete from Front\n"); 
        printf("4. Delete from End\n"); 
        printf("5. Display\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        switch (choice) { 
            case 1: 
                printf("Enter number to insert at front: "); 
                scanf("%d", &num); 
                start = insertfrontend(start, num); 
                break; 

            case 2: 
                printf("Enter number to insert at end: "); 
                scanf("%d", &num); 
                start = insertend(start, num); 
                break; 

            case 3: 
                start = deletefront(start); 
                break; 

            case 4: 
                start = deleteend(start); 
                break; 

            case 5: 
                display(start); 
                break; 

            case 6: 
                exit(0); 

            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
}

// Insert node at front
NODE* insertfrontend(NODE *start, int n) 
{ 
    NODE *new_node, *ptr; 
    new_node = (NODE *) malloc(sizeof(NODE));  
    new_node->data = n; 

    if (start == NULL) {             
        start = new_node; 
        start->next = start; 
    } 
    else { 
        ptr = start;   
        while (ptr->next != start) { 
            ptr = ptr->next; 
        } 
        new_node->next = start; 
        ptr->next = new_node; 
        start = new_node; 
    } 
    return start; 
}  

// Insert node at end
NODE* insertend(NODE *start, int n) 
{ 
    NODE *new_node, *ptr; 
    new_node = (NODE *) malloc(sizeof(NODE));  
    new_node->data = n; 

    if (start == NULL) {            
        start = new_node; 
        start->next = start; 
    } 
    else { 
        ptr = start;   
        while (ptr->next != start) { 
            ptr = ptr->next; 
        } 
        ptr->next = new_node;
        new_node->next = start; 
    } 
    return start; 
}  

// Delete node from front
NODE* deletefront(NODE *start) 
{ 
    NODE *ptr, *temp; 

    if (start == NULL) {             
        printf("List Empty\n"); 
        return start; 
    } 

    if (start->next == start) {             
        printf("Item deleted: %d\n", start->data); 
        free(start); 
        return NULL; 
    } 
    else { 
        ptr = start;        
        while (ptr->next != start) { 
            ptr = ptr->next; 
        } 
        temp = start;  
        start = start->next; 
        ptr->next = start;              
        printf("Item deleted: %d\n", temp->data); 
        free(temp); 
    } 
    return start; 
}  

// Delete node from end
NODE* deleteend(NODE *start) 
{ 
    NODE *ptr, *temp; 
      
    if (start == NULL) {             
        printf("List Empty\n"); 
        return start; 
    } 
    if (start->next == start) {             
        printf("Item deleted: %d\n", start->data); 
        free(start); 
        return NULL; 
    } 
    else { 
        ptr = start;       
        while (ptr->next != start) {               
            temp = ptr; 
            ptr = ptr->next; 
        } 
        temp->next = start;   
        printf("Item deleted: %d\n", ptr->data); 
        free(ptr); 
        return start; 
    }  
} 

// Display list contents
void display(NODE *start) 
{ 
    NODE *ptr; 
    ptr = start; 
    if (ptr == NULL) {          
        printf("List is empty\n");  
        return;   
    } 
    printf("The list data are:\n"); 
    while(ptr->next != start) { 
        printf("%d\n", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("%d\n", ptr->data); 
    return;
} 


