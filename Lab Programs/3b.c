//) Write a program to reverse the linked list elements.
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE *insertfront(NODE *, int);
NODE *reverse(NODE *);
void display(NODE *);

// Main function
int main() {
    NODE* start = NULL;
    int num, choice;
    while (1) {
        printf("\nEnter your choice\n");
        printf("1. Insert at front\n2. Reverse\n3. Display\n4. Stop\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                start = insertfront(start, num);
                break;
            case 2:
                start = reverse(start);
                printf("List reversed successfully.\n");
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to insert a node at the front
NODE* insertfront(NODE* start, int n) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = n;
    new_node->next = start;
    start = new_node;
    return start;
}

// Function to display the list
void display(NODE* start) {
    NODE* ptr = start;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List data: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to reverse the linked list
NODE* reverse(NODE* start) {
    NODE *prev = NULL, *temp, *ptr = start;

    if (start == NULL) {
        printf("List Empty\n");
        return start;
    }

    while (ptr != NULL) {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }

    return prev;
}
/*

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter the number to insert: 4

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter the number to insert: 3

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter the number to insert: 2

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter the number to insert: 5

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
3
Linked List data: 5 2 3 4 

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
2
List reversed successfully.

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
3
Linked List data: 4 3 2 5 

Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
4

*/


