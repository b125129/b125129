#include<stdio.h>

typedef struct {
    int roll;
    char name[100];
    float cgpa;
}student;

void main(){
    student s[5];
    printf("Enter roll, name and cgpa of the student:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Enter details of Student %d",i+1);
        scanf("%d",&s[i].roll);
        scanf("%s",s[i].name);
        scanf("%f",&s[i].cgpa);
    }

    printf("Details of students with CGPA greater than or equal to 8.0 are as follows");

    for (int i = 0; i < 5; i++)
    {
        if (s[i].cgpa>=8.0)
        {
            printf("\n Roll No: %d\n Name:%s \n CGPA: %.2f \n\n" ,s[i].roll , s[i].name ,s[i].cgpa);
        }
    }
}
