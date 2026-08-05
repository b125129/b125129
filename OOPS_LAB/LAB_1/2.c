#include <stdio.h> //included library for standarad input and output

//define the required structure
typedef struct{
    int empID;
    char name[100];
    float salary;
}Employee;

int main(){
    // Declare a variable array of type Employee
    Employee employee[3];
    int i; // loop counter
    // loop for inputing values into the array of structure employee
    for(i = 0; i < 3; i++){
        printf("\nEnter details of Employees %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employee[i].empID);
        printf("Name: ");
        scanf("%s", employee[i].name);
        printf("Salary: ");
        scanf("%f", &employee[i].salary);
    }

    // Display the stored student details
    printf("\nEmployee Details:\n");

    for(i = 0; i < 3; i++){
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", employee[i].empID);
        printf("Name: %s\n", employee[i].name);
        printf("Salary: %.2f\n", employee[i].salary);
    }
    return 0;
}
