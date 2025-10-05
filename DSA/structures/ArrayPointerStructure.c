//Write a program, using an array of pointers to a structure, to read and display the data of students. 

#include <stdio.h> 
#include <stdlib.h>
struct student { 
    int r_no; 
    char name[20]; 
    char course[20]; 
    int fees; 
}; 
struct student *ptr_stud[10]; 
int main() { 
    int i, n; 
    printf("Enter the number of students : "); 
    scanf("%d", &n); 
    for(i=0;i<n;i++) { 
        ptr_stud[i] = (struct student *)malloc(sizeof(struct student));
        printf("Enter details of student %d\n", i+1);
        printf("ROLL NO.: "); 
        scanf("%d", &ptr_stud[i]->r_no); 
        printf("NAME: "); 
        scanf("%s", ptr_stud[i]->name); 
        printf("COURSE: "); 
        scanf("%s", ptr_stud[i]->course); 
        printf("FEES: "); 
        scanf("%d", &ptr_stud[i]->fees); 
    } 
    printf("-------DETAILS OF STUDENTS-------\n"); 
    for(i=0;i<n;i++) { 
        printf("STUDENT %d\n", i+1);
        printf("ROLL NO. = %d  || ", ptr_stud[i]->r_no); 
        printf("NAME = %s  || ", ptr_stud[i]->name); 
        printf("COURSE = %s  || ", ptr_stud[i]->course); 
        printf("FEES = %d \n", ptr_stud[i]->fees); 
    } 
    return 0; 
}

// Sample Input and Output
// Enter the number of students : 2
// Enter details of student 1
// ROLL NO.: 101
// NAME: Alice
// COURSE: CS
// FEES: 5000
// Enter details of student 2
// ROLL NO.: 102
// NAME: Bob
// COURSE: EE
// FEES: 6000
// -------DETAILS OF STUDENTS-------
// STUDENT 1
// ROLL NO. = 101  || NAME = Alice  || COURSE = CS  || FEES = 5000
// STUDENT 2
// ROLL NO. = 102  || NAME = Bob  || COURSE = EE  || FEES = 6000