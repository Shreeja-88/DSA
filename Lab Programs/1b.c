// Write a program to search for a given element in an array using pointers. 
#include<stdio.h>
void search(int *, int *, int *);
int main(){
    int arr[20];
    int n, i, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    search(arr, &n, &key);
    return 0;
}
void search(int *arr, int *n, int *key){
    int i, found = 0;
    for(i=0; i<*n; i++){
        if(*arr == *key){
            printf("Element %d found at position %d\n", *key, i);
            found = 1;
            break;
        }
        arr++;
    }
    if(!found){
        printf("Element %d not found in the array\n", *key);
    }
}