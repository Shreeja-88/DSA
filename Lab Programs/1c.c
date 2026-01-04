//Write a program to find the maximum element in each row of a matrix using pointers. 
#include<stdio.h>
void maxi_row(int (*p)[20], int *r, int *c);
int main(){
    int matrix[20][20];
    int r, c, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of the matrix:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    maxi_row(matrix, &r, &c);
    return 0;
}
void maxi_row(int (*p)[20], int *r, int *c){
    int i, j;
    int max =0;
    for(i=0; i<*r; i++){
        for(j=1; j<*c; j++){
            if(p[i][j] > max){
                max = p[i][j];
            }
        }
        printf("Maximum element in row %d is: %d\n", i+1, max);
    }
}

/*
Enter number of rows and columns: 2 2
Enter the elements of the matrix:
2 4 
7 6
Maximum element in row 1 is: 4
Maximum element in row 2 is: 6
*/