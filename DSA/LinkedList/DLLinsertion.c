/*
Inserting a New Node in a Doubly Linked List->

Case 1: The new node is inserted at the beginning. 
Case 2: The new node is inserted at the end. 
Case 3: The new node is inserted after a given node. 
Case 4: The new node is inserted before a given node 
Case 5: The new node is inserted at a particular position
*/

#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    struct node *leftlink;  
    int data;  
    struct node *rlink; 
}; 
typedef struct node NODE; 
 
NODE* insertfront(NODE *, int);  
NODE* insertend(NODE *, int);  
NODE* i_afterkey(NODE *, int, int);  
NODE* i_beforekey(NODE *, int, int);  
NODE* i_pos(NODE *, int, int);  
void display(NODE *);  
 
void main() { 
    NODE *start = NULL; 
    int num, choice, k, p;
    while (1) { 
        printf("\nEnter your choice\n"); 
        printf("1. Insert at front\n"); 
        printf("2. Insert at end\n"); 
        printf("3. Insert after data\n"); 
        printf("4. Insert before data\n"); 
        printf("5. Insert at a position\n"); 
        printf("6. Display\n"); 
        printf("7. Stop\n"); 
        scanf("%d", &choice); 

        switch (choice) { 
            case 1: 
                printf("Enter data to insert: "); 
                scanf("%d", &num); 
                start = insertfront(start, num); 
                break; 

            case 2: 
                printf("Enter data to insert: "); 
                scanf("%d", &num); 
                start = insertend(start, num); 
                break; 

            case 3: 
                printf("Enter data and key: "); 
                scanf("%d%d", &num, &k); 
                start = i_afterkey(start, num, k); 
                break; 

            case 4: 
                printf("Enter data and key: "); 
                scanf("%d%d", &num, &k); 
                start = i_beforekey(start, num, k); 
                break; 

            case 5: 
                printf("Enter data and position: "); 
                scanf("%d%d", &num, &p); 
                start = i_pos(start, num, p); 
                break; 

            case 6:  
                display(start); 
                break; 

            case 7: 
                exit(0); 
        }  
    } 
} 

void display(NODE *start) { 
    NODE *ptr = start; 
    if (start == NULL) {          
        printf("List is empty\n");  
    } else { 
        printf("The list data are:\n"); 
        while (ptr != NULL) { 
            printf("%d ", ptr->data); 
            ptr = ptr->rlink; 
        } 
        printf("\n");
    } 
}

// Case 1: Insert at front
NODE* insertfront(NODE *start, int n) { 
    NODE *new_node;   
    new_node = (NODE *)malloc(sizeof(struct node));  
    new_node->data = n; 
    new_node->leftlink = NULL; 
    new_node->rlink = NULL; 

    if (start == NULL) { 
        start = new_node; 
    } else { 
        new_node->rlink = start; 
        start->leftlink = new_node; 
        start = new_node; 
    } 
    return start; 
}

// Case 2: Insert at end
NODE* insertend(NODE *start, int n) { 
    NODE *new_node, *ptr; 
    new_node = (NODE *) malloc(sizeof(struct node));  
    new_node->data = n; 
    new_node->leftlink = NULL; 
    new_node->rlink = NULL; 

    if (start == NULL) { 
        start = new_node; 
    } else { 
        ptr = start; 
        while (ptr->rlink != NULL) { 
            ptr = ptr->rlink; 
        } 
        ptr->rlink = new_node; 
        new_node->leftlink = ptr; 
    } 
    return start;    
}

// Case 3: Insert after a given node
NODE* i_afterkey(NODE *start, int n, int key) { 
    NODE *new_node, *ptr; 
    new_node = (NODE *) malloc(sizeof(struct node));  
    new_node->data = n; 
    new_node->leftlink = NULL; 
    new_node->rlink = NULL; 

    if (start == NULL) {     
        printf("List Empty\n"); 
    } else { 
        ptr = start; 
        while ((ptr != NULL) && (ptr->data != key)) { 
            ptr = ptr->rlink; 
        }       
        if (ptr == NULL) { 
            printf("Invalid key\n"); 
        } else {  
            new_node->rlink = ptr->rlink; 
            if (ptr->rlink != NULL) {                 
                (ptr->rlink)->leftlink = new_node; 
            } 
            new_node->leftlink = ptr; 
            ptr->rlink = new_node; 
        } 
    } 
    return start;    
} 

// Case 4: Insert before a given node
NODE* i_beforekey(NODE *start, int n, int key) { 
    NODE *new_node, *temp, *ptr; 
    new_node = (NODE *) malloc(sizeof(struct node));  
    new_node->data = n; 
    new_node->rlink = NULL; 
    new_node->leftlink = NULL; 
 
    if (start == NULL) {     
        printf("List Empty, cannot insert\n"); 
    } else if (start->data == key) { 
        new_node->rlink = start; 
        start->leftlink = new_node;  
        start = new_node; 
    } else {    
        ptr = start; 
        while ((ptr != NULL) && (ptr->data != key)) {     
            temp = ptr; 
            ptr = ptr->rlink; 
        } 
        if (ptr == NULL) { 
            printf("Invalid key\n"); 
        } else { 
            new_node->rlink = ptr;  
            ptr->leftlink = new_node; 
            new_node->leftlink = temp; 
            temp->rlink = new_node;    
        } 
    } 
    return start;
}

// Case 5: Insert at a position
NODE* i_pos(NODE *start, int n, int position) { 
    NODE *new_node, *ptr, *temp; 
    int count; 
    new_node = (NODE *) malloc(sizeof(struct node));  
    new_node->data = n; 
    new_node->rlink = NULL; 
    new_node->leftlink = NULL; 
 
    if ((start == NULL) && (position == 1)) {  
        start = new_node;     
    } else if ((start == NULL) && (position > 1)) {     
        printf("Invalid position\n"); 
    } else if (start != NULL && position == 1) { 
        new_node->rlink = start; 
        start->leftlink = new_node; 
        start = new_node; 
    } else { 
        count = 1;        
        ptr = start; 
        while ((ptr != NULL) && (count != position)) { 
            temp = ptr; 
            ptr = ptr->rlink;                          
            count++; 
        } 
        if (ptr == NULL && count != position) 
            printf("Invalid position\n"); 
        else { 
            new_node->rlink = ptr;  
            if (temp->rlink != NULL) { 
                ptr->leftlink = new_node; 
            } 
            new_node->leftlink = temp; 
            temp->rlink = new_node;    
        } 
    }     
    return start;    
}

