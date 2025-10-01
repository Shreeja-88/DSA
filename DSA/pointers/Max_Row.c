//1.C) Write a C program to find the maximum element in each row of the matrix using pointers.

#include<stdio.h> 
void maxi_row(int (*p)[20], int *r, int *c); 
int main() 
{ 
    int m, n,mat1[20][20],i,j;
    printf("Enter the number of rows and columns: "); 
    scanf("%d%d",&m,&n); 
    printf("Enter the elements of the matrix: /n");
    for(i = 0; i < m; i++) 
    { 
        for(j = 0; j < n; j++) 
        scanf("%d",&mat1[i][j]); 
    } 
    maxi_row(mat1,&m,&n); 
    return 0; 
} 
void maxi_row(int (*p)[20], int *r, int *c) 
{ 
    int i = 0, j; 
    int max = 0; 
    int result[20]; 
    for(i=0;i<*r;i++) 
    { 
        for ( j = 0; j < *c; j++) 
        { 
            if (p[i][j]> max) 
            { 
                max =p[i][j]; 
            } 
         } 
        result[i] = max; 
        max = 0; 
    } 
    for(i = 0; i < *r; i++) 
    { 
        printf("Maximum element in row %d is %d\n",i+1,result[i]);
    } 
} 

//output -> Enter the number of rows and columns: 3 3
//          Enter the elements of the matrix:
//          1 2 3
//          4 5 6
//          7 8 9
//          Maximum element in row 1 is 3
//          Maximum element in row 2 is 6
//          Maximum element in row 3 is 9
