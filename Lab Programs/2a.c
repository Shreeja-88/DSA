// Define a structure TIME with hour, minute, second, and a self-referencing pointer. 
//Dynamically create two variables, link them, and display in h:m:s format. 
#include<stdio.h>
#include<stdlib.h>
struct time{
    int hour;
    int min;
    int sec;
    struct time* next;
};
void display(struct time* t){
    struct time* ptr = t;
    while(ptr != NULL){
        printf("%d:%d:%d\n", ptr->hour, ptr->min, ptr->sec);
        ptr = ptr->next;
    }
}
int main(){
    struct time *t1, *t2;
    t1 = (struct time*)malloc(sizeof(struct time));
    t2 = (struct time*)malloc(sizeof(struct time));
    printf("Enter time 1 (hour min sec): ");
    scanf("%d %d %d", &t1->hour, &t1->min, &t1->sec);
    printf("Enter time 2 (hour min sec): ");
    scanf("%d %d %d", &t2->hour, &t2->min, &t2->sec);
    t1->next = t2;
    t2->next = NULL;
    printf("The times are:\n");
    display(t1);
    return 0;
}

//output:
//Enter time 1 (hour min sec): 10 20 30
//Enter time 2 (hour min sec): 12 30 45
//The times are:
//10:20:30
//12:30:45