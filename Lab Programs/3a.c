//Implement a singly linked list with operations: insert at front, insert at position, delete by 
//value, search, and display.

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node NODE;
NODE* insertfront(NODE*, int);
NODE* i_pos(NODE*, int, int);
NODE* del_by_value(NODE*, int);
NODE* search(NODE*, int);
void display(NODE*);
void main(){
    NODE *start = NULL;
    int num, choice;

    while(1){
        printf("\n");
        printf("Enter your choice: \n");
        printf("\n1.Insert at front\n2.Insert at a position\n3.Delete by value\n4.Search\n5.Display\n6.Stop\n");
        printf("\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                start = insertfront(start, num);
                break;
            case 2:
                {
                    int pos;
                    printf("Enter the position to insert at (0-based index): ");
                    scanf("%d", &pos);
                    printf("Enter the number to be inserted: ");
                    scanf("%d", &num);
                    start = i_pos(start, pos, num);
                }
                break;
            case 3:
                {
                    int val;
                    printf("Enter the value to be deleted: ");
                    scanf("%d", &val);
                    start = del_by_value(start, val);
                }
                break;
            case 4:
                {
                    int val;
                    printf("Enter the value to search: ");
                    scanf("%d", &val);
                    NODE* result = search(start, val);
                    if(result != NULL){
                        printf("Value %d found in the list.\n", val);
                    } else {
                        printf("Value %d not found in the list.\n", val);
                    }
                }
                break;
            case 5:
                display(start);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
NODE* insertfront(NODE* start, int n){
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    newnode->next = start;
    start = newnode;
    return start;
}
NODE* i_pos(NODE* start, int position, int n){
    NODE *newnode, *ptr, *temp;
    int count;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    if((start==NULL)&&(position ==0)){
        newnode->next = NULL;
        start = newnode;
    }
    else if((start==NULL)&&(position>0)){
        printf("Invalid Position.\n");
    }
    else{
        count = 0;
        ptr = start;
        while((ptr!=NULL)&&(count != position)){
            temp = ptr;
            ptr = ptr->next;
            count++;
        }
        if(ptr == NULL && count != position){
            printf("Invalid Position.\n");
        }else if(count == position){
            if(position == 0){ // Insert at the front
                newnode->next = start;
                start = newnode;
            } else {
                newnode->next = ptr;
                temp->next = newnode;
            }
        }
    }
    return start;
}
NODE* del_by_value(NODE* start, int val){
    NODE *ptr, *temp;
    if(start == NULL){
        printf("List is empty. Cannot delete.\n");
        return start;
    }
    if(start->data == val){ // Deleting the first node
        ptr = start;
        start = start->next;
        free(ptr);
        return start;
    }
    ptr = start;
    while(ptr != NULL && ptr->data != val){
        temp = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Value %d not found in the list.\n", val);
    } else {
        temp->next = ptr->next;
        free(ptr);
        printf("Value %d deleted from the list.\n", val);
    }
    return start;
}

NODE* search(NODE* start, int val){
    NODE* ptr = start;
    while(ptr != NULL){
        if(ptr->data == val){
            return ptr; // Value found
        }
        ptr = ptr->next;
    }
    return NULL; // Value not found
}

void display(NODE* start){
    NODE* ptr;
    if(start == NULL){
        printf("List is empty.\n");
    } else {
        ptr = start;
        printf("The linked list is: \n");
        while(ptr != NULL){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}