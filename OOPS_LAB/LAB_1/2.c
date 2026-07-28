#include <stdio.h>

typedef struct{
    int empID;
    char name[100];
    float salary;
}Employee;

void main(){
    Employee employee[3];
    int i;
    for(i = 0; i < 3; i++){
        printf("\nEnter details of Employees %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employee[i].empID);
        printf("Name: ");
        scanf("%s", employee[i].name);
        printf("Salary: ");
        scanf("%f", &employee[i].salary);
    }

    printf("\nEmployee Details:\n");

    for(i = 0; i < 3; i++){
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", employee[i].empID);
        printf("Name: %s\n", employee[i].name);
        printf("Salary: %.2f\n", employee[i].salary);
    }
}