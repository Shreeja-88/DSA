#include<stdio.h>  
int sum(int *arr,int *p);  
int main()  {  
    int i,n,s;  
    int a[20]; 
    printf("Enter the number of elements in the array: "); 
    scanf("%d",&n);  
    printf("Enter the elements in the array: ");
    for(i=0;i<n;i++)  
    scanf("%d",&a[i]);  
    s = sum(a,&n); 
    printf("The sum of the elements in the array is %d\n",s);  
    return 0;  
}   
int sum(int *arr, int *p)  {  
    int i,sum = 0;  
    for(i=0;i<*p;i++)  
    sum +=arr[i];  
    return sum;  
} 

//Output -> Enter the number of elements in the array: 5
//          Enter the elements in the array: 1 2 3 4 5
//          The sum of the elements in the array is 15
//In this program, we define a function sum that takes a pointer to an integer array and a pointer to an integer (the size of the array) as arguments.
//We use pointer arithmetic to iterate through the array and calculate the sum of its elements. The result is returned to the main function and printed.