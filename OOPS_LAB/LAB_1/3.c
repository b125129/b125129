#include<stdio.h> //included library for standarad input and output

//define the required structure
typedef struct {
    int book_id;
    char title[50];
    char auth_name[50];
    float price;
}book;

int main(){
    book b1; // Declare a variable b1 of type book
    // Input values from the user and store them in structure member
    printf("Enter Book id, title, author name and price of the student:\n");
    scanf("%d",&b1.book_id);
    scanf("%s",b1.title);
    scanf("%s",b1.auth_name);
    scanf("%f",&b1.price);

    // Display the stored student details
    printf("Details of the Book are as follows.");
    printf("\n Book_id No: %d\n Title: %s \n Author name: %s \n Price: %.2f \n" ,b1.book_id ,b1.title, b1.auth_name ,b1.price);
    return 0;
}
