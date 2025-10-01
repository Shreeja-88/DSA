#include <stdio.h> 
int main() { 
    int num, *pnum; 
    pnum = &num;    
    printf("Enter the number : "); 
    scanf("%d", &num); 
    printf("The address of num is : %p\n", &num);
    printf("The number that was entered is : %d\n", *pnum); 
    return 0;
} 

//output -> Enter the number : 5
//          The address of num is : 0x7ffee3b8c9ac
//          The number that was entered is : 5