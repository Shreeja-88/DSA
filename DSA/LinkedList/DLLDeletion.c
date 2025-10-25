/*
Deleting a Node from a Doubly Linked List-> 
Case 1: Deleting the start Node from a DLL 
Case 2: Deleting the Last Node from a DLL 
Case 3: Delete at a position 
Case 4: Delete a key node 
Case 5: Delete after a key number 
Case 6: Delete before a key number 
*/

#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    struct node *leftlink;  
    int data;  
    struct node *rlink; 
}; 
typedef struct node NODE; 
 
NODE* deletefront(NODE *);  
NODE* deleteend(NODE *);  
NODE* deleteposition(NODE *, int);  
NODE* deletekey(NODE *, int);  
NODE* deleteafterkey(NODE *, int);  
NODE* deletebeforekey(NODE *, int);  
void display(NODE *);  
 
void main() { 
    NODE *start = NULL; 
    int k, pos, choice;
    while (1) { 
        printf("\nEnter your choice\n"); 
        printf("1. Delete from front\n"); 
        printf("2. Delete from last\n"); 
        printf("3. Delete at a position\n"); 
        printf("4. Delete the key node\n"); 
        printf("5. Delete after the key\n"); 
        printf("6. Delete before key\n"); 
        printf("7. Display\n"); 
        printf("8. Stop\n"); 
        scanf("%d", &choice); 

        switch (choice) { 
            case 1:  
                start = deletefront(start); 
                break; 

            case 2:  
                start = deleteend(start); 
                break; 

            case 3: 
                printf("Enter the position: "); 
                scanf("%d", &pos); 
                start = deleteposition(start, pos); 
                break;

            case 4: 
                printf("Enter the key value: "); 
                scanf("%d", &k); 
                start = deletekey(start, k); 
                break; 

            case 5: 
                printf("Enter the key value: "); 
                scanf("%d", &k); 
                start = deleteafterkey(start, k); 
                break; 

            case 6: 
                printf("Enter the key value: "); 
                scanf("%d", &k); 
                start = deletebeforekey(start, k); 
                break; 

            case 7:  
                display(start); 
                break; 

            case 8: 
                exit(0); 
        }  
    } 
} 

// Display function
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

// Case 1: Delete front node
NODE* deletefront(NODE *start) { 
    NODE *ptr; 
    if (start == NULL) { 
        printf("List is empty\n");  
        return NULL; 
    } else { 
        ptr = start; 
        start = start->rlink; 
        if (start != NULL)
            start->leftlink = NULL;
        printf("Item deleted: %d\n", ptr->data); 
        free(ptr); 
        return start; 
    } 
}

// Case 2: Delete last node
NODE* deleteend(NODE *start) { 
    NODE *ptr, *temp; 
    if (start == NULL) { 
        printf("List Empty\n"); 
        return NULL; 
    } else if (start->rlink == NULL) { 
        printf("Deleted item: %d\n", start->data); 
        free(start); 
        return NULL; 
    } else { 
        ptr = start; 
        while (ptr->rlink != NULL) { 
            temp = ptr; 
            ptr = ptr->rlink; 
        } 
        temp->rlink = NULL; 
        printf("Deleted item: %d\n", ptr->data); 
        free(ptr); 
    } 
    return start;    
}

// Case 3: Delete at a given position
NODE* deleteposition(NODE *start, int pos) { 
    NODE *temp, *ptr; 
    int count = 1; 
        
    if (start == NULL) {     
        printf("List Empty\n"); 
        return NULL; 
    } 
    if (pos == 1) { 
        ptr = start; 
        printf("Item deleted: %d\n", ptr->data); 
        start = start->rlink; 
        if (start != NULL)
            start->leftlink = NULL;
        free(ptr); 
        return start; 
    } else { 
        ptr = start;
        while ((ptr != NULL) && (count != pos)) { 
            temp = ptr; 
            ptr = ptr->rlink; 
            count++; 
        } 
        if (ptr == NULL) { 
            printf("Invalid position\n"); 
        } else { 
            temp->rlink = ptr->rlink; 
            if (ptr->rlink != NULL) { 
                (ptr->rlink)->leftlink = temp; 
            } 
            printf("Item deleted: %d\n", ptr->data);    
            free(ptr); 
        } 
        return start;   
    }  
}

// Case 4: Delete key node
NODE* deletekey(NODE *start, int key) { 
    NODE *ptr, *temp;        
    if (start == NULL) { 
        printf("List Empty\n"); 
    } else if (start->data == key) { 
        ptr = start; 
        start = start->rlink; 
        if (start != NULL)
            start->leftlink = NULL;
        printf("Item Deleted: %d\n", ptr->data);  
        free(ptr); 
    } else { 
        ptr = start; 
        while ((ptr != NULL) && (ptr->data != key)) { 
            temp = ptr; 
            ptr = ptr->rlink; 
        } 
        if (ptr == NULL)  
            printf("Invalid key number\n"); 
        else { 
            temp->rlink = ptr->rlink; 
            if (ptr->rlink != NULL) { 
                (ptr->rlink)->leftlink = temp; 
            } 
            printf("Item deleted: %d\n", ptr->data);    
            free(ptr); 
        } 
    } 
    return start;   
}

// Case 5: Delete after a key
NODE* deleteafterkey(NODE *start, int key) { 
    NODE *ptr, *temp; 
    if (start == NULL) {     
        printf("List Empty\n"); 
        return start; 
    } else { 
        ptr = start; 
        while ((ptr != NULL) && (ptr->data != key)) { 
            ptr = ptr->rlink; 
        } 
        if (ptr == NULL) { 
            printf("Key not found\n"); 
        } else if (ptr->rlink == NULL) { 
            printf("Key is in the last node, deletion not possible\n"); 
        } else { 
            temp = ptr->rlink; 
            ptr->rlink = temp->rlink; 
            if (temp->rlink != NULL) { 
                (temp->rlink)->leftlink = ptr; 
            } 
            printf("Item deleted: %d\n", temp->data);  
            free(temp); 
        } 
        return start;     
    } 
}

// Case 6: Delete before a key
NODE* deletebeforekey(NODE *start, int key) { 
    NODE *temp, *ptr, *prev; 
    if (start == NULL) {  
        printf("List Empty\n"); 
        return start;  
    } 
    if (start->data == key) { 
        printf("Delete not possible\n");          
        return start;      
    } 
    // if 2nd node is the key then delete start node 
    ptr = start->rlink;            
    if (ptr != NULL && ptr->data == key) {        
        printf("Item deleted: %d\n", start->data);                                              
        free(start);  
        ptr->leftlink = NULL;
        start = ptr;                
    } else { 
        prev = start; 
        temp = start->rlink; 
        ptr = (start->rlink)->rlink; 
        while ((ptr != NULL) && (ptr->data != key)) { 
            prev = prev->rlink; 
            temp = temp->rlink; 
            ptr = ptr->rlink; 
        } 
        if (ptr == NULL)  
            printf("Invalid key\n"); 
        else { 
            prev->rlink = ptr; 
            ptr->leftlink = prev; 
            printf("Item deleted: %d\n", temp->data);    
            free(temp); 
        } 
    }   
    return start;    
}
