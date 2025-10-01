//1.b) Write a program to search for a given element in an array using pointers.

#include<stdio.h> 
#include<stdlib.h> 
void search(int *,int *, int *); 
int i; 
int main() 
{     
 int a[20],n,key;     
 printf("Enter the size of the array: ");     
 scanf("%d",&n);     
 printf("Enter the elements into an array: ");     
 for(i=0;i<n;i++)     
 {        
   scanf("%d",&a[i]);             
 }     
 printf("Enter the key to be searched: ");    
 scanf("%d",&key);     
 search(a,&n,&key);     
 return 0; 
} 
void search(int *p, int *n1, int *k) 
{     
 int flag=0;     
 for(i=0;i<*n1;i++)     
 {         
  if(*p==*k)         
  { 
    flag=1;             
    printf("The element %d found at %dth position.",*k,i);             
        exit(0);         
  }         
  p++;     
 }     
if(flag==0)     
 {        
  printf("The element not found!");     
 } 
} 

//output -> Enter the size of the array: 5
//          Enter the elements into an array: 2 4 6 8 10
//          Enter the key to be searched: 8
//          The element 8 found at 3th position.
