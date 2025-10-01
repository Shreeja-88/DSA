//PASSING ARGUMENTS TO FUNCTION USING POINTERS  

#include <stdio.h> 
int main()  {  
    int num1, num2, total;  
    printf("Enter two numbers : ");  
    scanf("%d %d", &num1, &num2);  
    sum(&num1, &num2, &total);  
    printf("Total = %d", total);  
    return 0;  
}  
void sum( int *a, int *b, int *t)  {  
    *t = *a + *b;  
} 
//Output -> Enter two numbers : 5 7
//          Total = 12
