//Case 1: Deleting the First Node from a Linked List 
//Case 2: Deleting the Last Node from a Linked List 
//Case 3: Delete at a position 
//Case 4: Delete a key node 
//Case 5: Delete after a key number 
//Case 6: Delete before a key number 

#include <stdio.h> 
#include <stdlib.h> 
 
struct node 
{ 
    int data; 
    struct node *next; 
}; 
typedef struct node NODE; 
 
NODE* deletefront(NODE *);  
NODE* deleteend(NODE *);  
NODE* deleteposition(NODE *, int);  
NODE* deletekey(NODE *, int);  
NODE* deleteafterkey(NODE *, int);  
NODE* deletebeforekey(NODE *, int);  
 
void display(NODE *);  
 
void main() 
{ 
    NODE *start = NULL; 
    int pos, k, choice; 
 
    while(1) 
    { 
        printf("\n"); 
        printf("Enter your choice: \n"); 
        printf("\n1.Delete at front\n2.Delete at last\n3.Delete at a position\n4.Delete a key node\n5.Delete after a key number\n6.Delete before a key number\n7.Display\n8.Stop\n"); 
        printf("\n"); 
        scanf("%d", &choice); 
        switch(choice) 
        { 
            case 1: 
                start = deletefront(start); 
                break; 
            case 2: 
                start = deleteend(start); 
                break; 
            case 3: 
                { 
                    int pos; 
                    printf("Enter the position to delete (1-based index): "); 
                    scanf("%d", &pos); 
                    start = deleteposition(start, pos); 
                } 
                break; 
            case 4: 
                { 
                    int val; 
                    printf("Enter the key value to delete: "); 
                    scanf("%d", &val); 
                    start = deletekey(start, val); 
                } 
                break; 
            case 5: 
                { 
                    int key; 
                    printf("Enter the key value after which to delete: "); 
                    scanf("%d", &key); 
                    start = deleteafterkey(start, key); 
                } 
                break; 
            case 6: 
                { 
                    int key; 
                    printf("Enter the key value before which to delete: "); 
                    scanf("%d", &key); 
                    start = deletebeforekey(start, key); 
                } 
                break; 
            case 7: 
                display(start); 
                break; 
            case 8: 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
}

NODE* deletefront(NODE* start) 
{ 
    NODE *ptr; 
    if(start == NULL) 
    { 
        printf("List is empty. Cannot delete.\n"); 
        return start; 
    } 
    ptr = start; 
    start = start->next;
    printf("Deleted element is %d\n", ptr->data); 
    free(ptr); 
    return start; 
}

NODE* deleteend(NODE* start) 
{ 
    NODE *ptr, *temp; 
    if(start == NULL) 
    { 
        printf("List is empty. Cannot delete.\n"); 
        return start; 
    } 
    if(start->next == NULL) // Only one node in the list 
    { 
        printf("Deleted element is %d\n", start->data); 
        free(start); 
        return NULL; 
    } 
    else{
        ptr = start; 
        while(ptr->next != NULL) { 
            temp = ptr; 
            ptr = ptr->next; 
        } 
        temp->next = NULL; 
        printf("Deleted element is %d\n", ptr->data); 
        free(ptr); 
    }
    return start; 
}

NODE* deleteposition(NODE* start, int pos){
    NODE *ptr, *temp;
    int count;
    if(start==NULL){
        printf("List empty");
        return NULL;
    }
    if((start ->next== NULL)&&(pos == 1)) //1 node 
    { 
        printf("Item deleted: %d\n",start->data);               
        free(start); 
        return NULL; 
    }
    else    //    more than one node 
   { 
        count =1;        
        ptr = start; 
        while((ptr != NULL) && (count !=pos)) 
        { 
            temp = ptr; 
            ptr = ptr -> next; 
            count++; 
        } 
        if(ptr == NULL) 
       { 
            printf("Invalid postion\n"); 
        } 
        else 
        { 
            temp -> next = ptr->next; 
            printf(" Item deleted: %d\n",ptr->data);    
            free(ptr); 
        } 
   }
   return start;
}

NODE* deletekey(NODE *start,  int key) 
{ 
    NODE  *temp, *ptr; 
    if (start == NULL)  // No Nodes 
    { 
        printf("List Empty\n"); 
        return NULL; 
    } else if (start->data==key ) {//first node is key 
        ptr=start; 
        start = ptr->next; 
        printf("Item Deleted: %d\n", ptr->data);   
        free(ptr); 
    }  else { // Traverse till key is found or till last node 
        ptr=start; 
        while((ptr != NULL)&&(ptr->data !=key)) 
        { 
            temp=ptr; 
            ptr = ptr->next; 
        } 
        if(ptr == NULL)  // Searched till end of list 
            printf("Invalid key\n"); 
        else { 
            temp->next = ptr->next; 
            printf("Item deleted:  %d\n",ptr->data);    
            free(ptr); 
        } 
    } 
    return start;    
} 

NODE* deleteafterkey(NODE *start,  int key) {
    NODE  *temp, *ptr;
    if(start == NULL)  //No Nodes 
      {     
        printf("List Empty\n"); 
        return start; 
      } 
    if((start ->next== NULL)&&(start->data==key )) 
      {        //  Only One Node 
        printf("Delete not possible\n");               
      } else {    //  More than One Node 
            ptr=start; 
            temp=ptr->next; 
            while((ptr != NULL)&&(ptr->data !=key)) 
            { 
                ptr = temp; 
                temp = temp -> next; 
            } 
            if(ptr== NULL || (ptr->data==key && ptr ->next==NULL)) 
                printf("Invalid key\n"); 
            else 
            { 
                ptr->next = temp->next; 
                printf("Item deleted:  %d\n",temp->data);    
                free(temp); 
           } 
      } 
   return start;     
}

    
NODE* deletebeforekey(NODE *start,  int key) 
{ 
     NODE  *temp, *ptr, *prev; 
              
      if (start == NULL)  // No Nodes 
              printf("List Empty\n"); 
           
       else if(start->data==key )  
             printf("Delete not possible\n");               
            
// if second node is the key then delete the first  
//  and make second node (current)  as first 
       ptr = start->next;// point to second node         
       if (ptr->data ==key) 
          {        
                printf("Item deleted:  %d\n", start->data);                                          
                free(start);  
                start = ptr;            
           }   else {  // Traverse till key is found or till last node 
         prev = start; 
         temp = start->next; // second node 
         ptr = (start->next)->next; // Third node 
         while((ptr!= NULL)&&(ptr->data !=key)) 
         { 
            prev = prev->next; 
            temp = temp->next; 
            ptr = ptr->next; 
           } 
         if(ptr == NULL)  // Searched till end of list 
                   printf("Invalid key\n"); 
         else 
         { 
            prev->next = ptr; 
            printf("Item deleted:  %d\n",temp->data);    
            free(temp); 
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