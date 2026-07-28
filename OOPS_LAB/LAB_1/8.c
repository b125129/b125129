#include <stdio.h>

typedef struct{
    int empID;
    char name[100];
    float salary;
}Employee;

void main(){
    Employee employee[5];
    int i;
    for(i = 0; i < 5; i++){
        printf("\nEnter details of Employees %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employee[i].empID);
        printf("Name: ");
        scanf("%s", employee[i].name);
        printf("Salary: ");
        scanf("%f", &employee[i].salary);
    }

    int count,max_salary=employee[0].salary;
    for (int i = 0; i < 5; i++)
    {
        if (employee[i].salary>max_salary);
        {
            max_salary=employee[i].salary;
            count=i;
        } 
    }
    
    printf("\nDetails of Employee with maximum salary:\n");
    printf("Employee ID: %d\n", employee[count].empID);
    printf("Salary: %.2f\n", employee[count].salary);
    printf("Name: %s\n", employee[count].name);
}