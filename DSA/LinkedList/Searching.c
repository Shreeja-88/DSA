#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int search(struct Node* start, int key){
    struct Node* ptr=start;
    while(ptr!=NULL){
        if(ptr->data==key){
            return 1; // Key found
        }
        ptr=ptr->next;
    }
    return 0; // Key not found
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    // Allocate memory for nodes in the linked list in heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    // Link first and second nodes
    head->data=7;
    head->next=second;
    // Link second and third nodes
    second->data=11;
    second->next=third;
    // Terminate the list at the third node
    third->data=66;
    third->next=NULL;
    
    //int key = 11;
    int key=15;
    if(search(head, key)){
        printf("Key %d found in the linked list.\n", key);
    } else {
        printf("Key %d not found in the linked list.\n", key);
    }
    
    return 0;
}