#include <stdio.h>    //included library for standarad input and output

//define the required structure
typedef struct{
    int empID;
    char name[100];
    float salary;
}Employee;

int main(){
    Employee employee[5];    //Declare an array of structure to store multiple employee data    
    int i; //loop counter
    
    //loop for storing data of multiple employees.
    for(i = 0; i < 5; i++){
        printf("\nEnter details of Employees %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employee[i].empID);
        printf("Name: ");
        scanf("%s", employee[i].name);
        printf("Salary: ");
        scanf("%f", &employee[i].salary);
    }

    // for loop to check for employee with maximum salary
    int count,max_salary=employee[0].salary;
    for (int i = 0; i < 5; i++)
    {
        if (employee[i].salary>max_salary);
        {
            max_salary=employee[i].salary;
            count=i;
        } 
    }

    // printing details of the employee with maximum salary
    printf("\nDetails of Employee with maximum salary:\n");
    printf("Employee ID: %d\n", employee[count].empID);
    printf("Salary: %.2f\n", employee[count].salary);
    printf("Name: %s\n", employee[count].name);
}
