#include<stdio.h> //included library for standarad input and output

typedef struct {    //define the required structure
    int roll;
    char name[100];
    int age;
    float cgpa;
}student;

int main(){
    student s1;    // Declare a variable s1 of type student

    // Input values from the user and store them in structure member
    printf("Enter roll, name, age and cgpa of the student:\n");
    scanf("%d",&s1.roll);
    scanf("%s",s1.name);
    scanf("%d",&s1.age);
    scanf("%f",&s1.cgpa);

    // Display the stored student details
    printf("Details of the student are as follows.");
    printf("\n Roll No: %d\n Name:%s \n Age: %d \n CGPA: %.2f \n" ,s1.roll , s1.name ,s1.age ,s1.cgpa);
    return 0;
}
