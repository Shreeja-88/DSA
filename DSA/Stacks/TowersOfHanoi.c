//C program: Towers of hanoi (using Recustion)->

#include<stdio.h>
void towerOfHanoi(int n, char source, char auxillary, char destination);

int main(){
    int n; 
    printf("Enter the number of disks: ");
    scanf("%d",&n);

    towerOfHanoi(n, 'A','B','C');
    return 0;
}

void towerOfHanoi(int n, char source, char auxillary, char destination){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",source, destination);
        return;
    }
    towerOfHanoi(n-1, source, destination, auxillary);
    printf("Move disk %d from %c to %c\n",n,source, destination);
    towerOfHanoi(n-1, auxillary,source,destination);
}