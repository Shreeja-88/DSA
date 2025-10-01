//1.a) Write a program to accept 3 integers and find the maximum among 3  numbers using function and pointers. 

#include<stdio.h> 
void largest(int *,int *, int *); 
int main() {     
    int n1,n2,n3;     
    printf("Enter 3 numbers: ");    
    scanf("%d%d%d",&n1,&n2,&n3);    
    largest(&n1,&n2,&n3);     
    return 0; 
}
void largest(int *a, int *b,int *c) {     
    int largest;     
    if((*a>*b)&&(*a>*c)) {         
        largest=*a;     
    } else if((*b>*a)&&(*b>*c))     {         
        largest=*b;        
    } else {     
        largest=*c; 
    }    
    printf("Largest = %d",largest); 
}

//output -> Enter 3 numbers: 5 4 2
//          Largest = 5