//Write a program using structures to read and display the information about a student. 

#include<stdio.h> 
int main() { 
    struct student { 
        int roll_no; 
        char name[80]; 
        float fees; 
        char DOB[80]; 
    }; 
    struct student stud1; 
    printf("Enter the roll number : "); 
    scanf("%d", &stud1.roll_no); 
    printf("Enter the name : "); 
    scanf("%s", stud1.name); 
    printf("Enter the fees : "); 
    scanf("%f", &stud1.fees); 
    printf("Enter the DOB : "); 
    scanf("%s", stud1.DOB);
    printf("******STUDENT'S DETAILS******\n"); 
    printf("ROLL No. = %d\n", stud1.roll_no); 
    printf("NAME = %s\n", stud1.name); 
    printf("FEES = %f\n", stud1.fees); 
    printf("DOB = %s\n", stud1.DOB); 
    return 0; 
}

/*
output:
Enter the roll number : 45
Enter the name : vishal
Enter the fees : 40000
Enter the DOB : 5-9-2002
******STUDENT'S DETAILS******
ROLL No. = 45
NAME = vishal
FEES = 40000.000000
DOB = 5-9-2002
*/

//Time Complexity: O(1)
//Space Complexity: O(1)