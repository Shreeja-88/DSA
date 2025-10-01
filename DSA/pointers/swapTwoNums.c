#include<stdio.h>  
void swap(int *p,int *q);  
int main()  {  
    int a,b;  
    printf("Enter the value of a & b: ");  
    scanf("%d%d",&a,&b);  
    printf("Before swapping: ");  
    printf("a = %d b = %d\n",a,b);  
    swap(&a,&b);  
    printf("After swapping: ");  
    printf("a = %d b = %d",a,b); 
    return 0;  
}  
void swap(int *p,int *q)  {  
    int temp;  
    temp = *p;  
    *p = *q;  
    *q = temp;  
}

//Output -> Enter the value of a & b: 5 7
//          Before swapping: a = 5 b = 7
//          After swapping: a = 7 b = 5