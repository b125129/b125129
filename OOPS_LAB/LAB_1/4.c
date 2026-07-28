#include<stdio.h>

typedef struct{
    int proid;
    char name[50];
    float price;
    int quantity;
} product;

void main(){
    product p;
    printf("Enter product Id : ");
    scanf("%d",&p.proid);
    printf("Enter name: "); 
    scanf("%s",p.name);
    printf("Enter price: ");
    scanf("%f",&p.price);
    printf("Enter quantity: ");
    scanf("%d",&p.quantity);
    printf("The Total Cost is %.2f" ,p.price*p.quantity);
}