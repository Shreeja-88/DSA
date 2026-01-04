// Write a program to accept 3 integers and determine the maximum using functions and pointers.  
#include<stdio.h>
void largerst(int *, int *, int *);
int main(){
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    largerst(&a, &b, &c);
    return 0;
}
void largerst(int *a, int *b, int *c){
    int largest;
    if(*a >= *b && *a >= *c){
        largest = *a;
    }
    else if(*b >= *a && *b >= *c){
        largest = *b;
    }
    else{
        largest = *c;
    }
    printf("Largest number is: %d\n", largest);
}