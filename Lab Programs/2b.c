// Define a structure Student with members name, USN, and marks in 3 subjects. Store n 
//student records, compute averages, and display in descending order of marks.

#include<stdio.h>
struct student{
    char name[20];
    int usn;
    int marks[20];
    float avg;
};
int main(){
    struct student s[20];
    int n, i, j, total=0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        total = 0;
        printf("Enter name, USN and marks in 3 subjects of student %d: ", i+1);
        scanf("%s %d", s[i].name, &s[i].usn);
        for(j=0; j<3; j++){
            scanf("%d", &s[i].marks[j]);
            total += s[i].marks[j];
        }
        s[i].avg = total/3.0;
    }
    //sorting in descending order of average marks
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i].avg < s[j].avg){
                struct student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("Student details in descending order of average marks:\n");
    for(i=0; i<n; i++){
        printf("Name: %s, USN: %d, Average Marks: %.2f\n", s[i].name, s[i].usn, s[i].avg);
    }
    return 0;
}
