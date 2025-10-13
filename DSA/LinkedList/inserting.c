//Case 1: The new node is inserted at the beginning. 
//Case 2: The new node is inserted at the end. 
//Case 3: The new node is inserted after a given node. 
//Case 4: The new node is inserted before a given node 
//Case 5: The new node is inserted at a particular position 

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node NODE;
NODE* insertfront(NODE*, int);
NODE* insertend(NODE*, int);
NODE* i_afterkey(NODE*, int, int);
NODE* i_beforekey(NODE*, int, int);
NODE* i_pos(NODE*, int, int);
void display(NODE*);

void main(){
    NODE *start = NULL;
    int num, choice;

    while(1){
        printf("\n");
        printf("Enter your choice: \n");
        printf("\n1.Insert at front\n2.Insert at last\n3.Insert after data\n4.Insert before data\n5.Insert at a position\n6.Display\n7.Stop\n");
        printf("\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                start = insertfront(start, num);
                break;
            case 2:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                start = insertend(start, num);
                break;
            case 3:
                {
                    int key;
                    printf("Enter the key after which to insert: ");
                    scanf("%d", &key);
                    printf("Enter the number to be inserted: ");
                    scanf("%d", &num);
                    start = i_afterkey(start, key, num);
                }
                break;
            case 4:
                {
                    int key;
                    printf("Enter the key before which to insert: ");
                    scanf("%d", &key);
                    printf("Enter the number to be inserted: ");
                    scanf("%d", &num);
                    start = i_beforekey(start, key, num);
                }
                break;
            case 5:
                {
                    int pos;
                    printf("Enter the position to insert at (0-based index): ");
                    scanf("%d", &pos);
                    printf("Enter the number to be inserted: ");
                    scanf("%d", &num);
                    start = i_pos(start, pos, num);
                }
                break;
            case 6:
                display(start);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
NODE* insertfront(NODE *start, int n){
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    newnode->next = start;
    start = newnode;
    return start;
}

NODE* insertend(NODE* start, int n){
    NODE *newnode, *ptr;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    newnode->next = NULL;
    if(start == NULL){
        start = newnode;
    } else {
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    return start;
}

NODE* i_afterkey(NODE* start, int key, int n){
    NODE *newnode, *ptr;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    if(start == NULL){   //no nodes 
        printf("List is empty.\n");
    } else {            //more than 1 node 
        ptr = start;    //traverse till key is found or till last node
        while(ptr != NULL && ptr->data != key){
            ptr = ptr->next;
        }
        if(ptr == NULL){
            printf("Invalid Key.\n");
        } else {    //key found
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }
    return start;
}

NODE* i_beforekey(NODE* start, int key, int n){
    NODE *newnode, *ptr, *temp;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    if(start == NULL){   //no nodes 
        printf("List is empty.\n");
    } else if(start->data == key){ //key is in first node
        newnode->next = start;
        start = newnode;
    } else {            //more than 1 node 
        ptr = start;    //traverse till key is found or till last node
        while(ptr != NULL && ptr->data != key){
            temp = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL){    //searched till last node, key not found
            printf("Invalid Key.\n");
        } else {    //key found
            newnode->next = ptr;
            temp->next = newnode;
        }
    }
    return start;
}

NODE* i_pos(NODE* start, int position, int n){
    NODE *newnode, *ptr, *temp;
    int count;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = n;
    if((start==NULL)&&(position ==1)){
        newnode->next = NULL;
        start = newnode;
    }
    else if((start==NULL)&&(position>1)){
        printf("Invalid Position.\n");
    }
    else{
        count = 1;
        ptr = start;
        while((ptr!=NULL)&&(count != position)){
            temp = ptr;
            ptr = ptr->next;
            count++;
        }
        if(ptr == NULL){
            printf("Invalid Position.\n");
        }else{
            newnode->next = ptr;
            temp->next = newnode;
        }
    }
    return start;
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