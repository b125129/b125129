#include<stdio.h>

typedef struct {
    int roll_no;
    char name[50];
    int mk_c;
    int mk_math;
    int mk_phy ;
}student;

void main(){
    student s1 ;
    printf("Enter roll number: ");
    scanf("%d",&s1.roll_no);
    printf("Enter name: ");
    scanf("%s",s1.name);
    printf("Enter marks in C: ");
    scanf("%d",&s1.mk_c);
    printf("Enter marks in Math:");
    scanf("%d",&s1.mk_math);
    printf("Enter marks in Physics:");
    scanf("%d",&s1.mk_phy);

    int total = s1.mk_c + s1.mk_math +s1.mk_phy ;

    printf("Name:%s \n Total and Average marks are : %d and %f respectively.",s1.name,total,total/3.0);
}