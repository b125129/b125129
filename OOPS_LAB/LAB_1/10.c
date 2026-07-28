#include <stdio.h>

struct Date{
    int day;
    int month;
    int year;
};

struct Student{
    int roll;
    char name[100];
    struct Date dob;
};

void main()
{
    struct Student s;

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

    printf("\nStudent Information:\n");
    printf("Roll Number: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Date of Birth: %d/%d/%d\n",s.dob.day, s.dob.month, s.dob.year);
}