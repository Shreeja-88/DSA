// A function may access the members of a structure in three ways.
// 1. By passing the individual members of the structure to the function.
// 2. By passing the entire structure to the function.
// 3. By passing the address of the structure to the function.

#include <stdio.h> 
struct POINT { 
    int x; 
    int y; 
}; 
void display(int, int); 
int main() { 
    struct POINT p1 = {2, 3}; 
    display(p1.x, p1.y); 
    return 0; 
} 
void display(int a, int b) { 
    printf(" The coordinates of the point are: %d %d", a, b); 
}
//output: The coordinates of the point are: 2 3

#include <stdio.h> 
struct POINT { 
    int x; 
    int y; 
}; 
void display(struct POINT); 
int main() { 
    struct POINT p1 = {2, 3}; 
    display(p1); 
    return 0; 
} 
void display(struct POINT p) { 
    printf("The coordinates of the point are: %d %d", p.x, p.y); 
}
//output: The coordinates of the point are: 2 3


#include <stdio.h> 
struct student { 
    int r_no; 
    char name[20]; 
    char course[20]; 
    int fees; 
}; 
int main() {
    struct student stud1, *ptr_stud1; 
    ptr_stud1 = &stud1; 
    printf("*******Enter the details of the student*******\n"); 
    printf("Enter the Roll Number = "); 
    scanf("%d", &ptr_stud1 -> r_no); 
    printf("Enter the Name = "); 
    scanf("%s",ptr_stud1 -> name); 
    printf("Enter the Course = "); 
    scanf("%s",ptr_stud1 -> course); 
    printf("Enter the Fees = "); 
    scanf("%d", &ptr_stud1 -> fees); 
    printf("*******DETAILS OF THE STUDENT*******\n"); 
    printf("ROLL NUMBER = %d\n", ptr_stud1 -> r_no); 
    printf("NAME = %s\n", ptr_stud1 -> name); 
    printf("COURSE = %s\n", ptr_stud1 -> course); 
    printf("FEES = %d\n", ptr_stud1 -> fees); 
    return 0; 
}

/*output:
*******Enter the details of the student*******
Enter the Roll Number = 45
Enter the Name = vishal
Enter the Course = Btech
Enter the Fees = 40000
*******DETAILS OF THE STUDENT*******
ROLL NUMBER = 45
NAME = vishal
COURSE = Btech
FEES = 40000
*/
//Time Complexity: O(1)
//Space Complexity: O(1)    
