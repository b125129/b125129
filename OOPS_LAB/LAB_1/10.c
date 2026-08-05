#include <stdio.h> //included library for standarad input and output

//define the required structure for storing date
struct Date{
    int day;
    int month;
    int year;
};

//define the required structure for storing student details
struct Student{
    int roll;
    char name[100];
    struct Date dob;
};

int main()
{
    struct Student s; // Declare a variable s of type student

    // Input values from the user and store them in structure member
    printf("Enter Student details:\n");
    printf("Roll Number: ");
    scanf("%d", &s.roll);
    printf("Name: ");
    scanf("%s", s.name);
    printf("Enter Date of Birth:\n");
    printf("Day: ");
    scanf("%d", &s.dob.day);
    printf("Month: ");
    scanf("%d", &s.dob.month);
    printf("Year: ");
    scanf("%d", &s.dob.year);

    // Display the stored student details
    printf("\nStudent Information:\n");
    printf("Roll Number: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Date of Birth: %d/%d/%d\n",s.dob.day, s.dob.month, s.dob.year);
    return 0;
}
