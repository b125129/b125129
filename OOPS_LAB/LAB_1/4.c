#include<stdio.h> //included library for standarad input and output

//define the required structure
typedef struct{
    int proid;
    char name[50];
    float price;
    int quantity;
} product;

int main(){
    product p; // Declare a variable p of type product
    // Input values from the user and store them in structure member
    printf("Enter product Id : ");
    scanf("%d",&p.proid);
    printf("Enter name: "); 
    scanf("%s",p.name);
    printf("Enter price: ");
    scanf("%f",&p.price);
    printf("Enter quantity: ");
    scanf("%d",&p.quantity);
    // calculating the total cost and displaying output
    printf("The Total Cost is %.2f" ,p.price*p.quantity);
    return 0;
}
