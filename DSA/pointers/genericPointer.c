#include <stdio.h> 
int main() { 
    int x=10; 
    char ch = 'A';
    void *gp; 
    gp = &x; 

    printf("\n Generic pointer points to the integer value = %d", *(int*)gp); 
    gp = &ch; 
    printf("\n Generic pointer now points to the character= %c", *(char*)gp); 
    return 0; 
} 

//Output 
//Generic pointer points to the integer value = 10 
//Generic pointer now points to the character = A 

//Generic pointers are used when you want a pointer to point to data of different types at different times. 
//You need to typecast the generic pointer to the appropriate data type before dereferencing it.