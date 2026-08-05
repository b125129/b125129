#include<stdio.h> //included library for standarad input and output

//define the required structure
typedef struct{
   float length ;
   float breadth ;
}rectangle;

int main(){
   rectangle r1; // Declare a variable r1 of type rectangle
   
   // Input values from the user and store them in structure member
   printf("Enter Length : ");
   scanf("%f",&r1.length);
   printf("Enter Breadth : ");
   scanf("%f",&r1.breadth);

   // Display the stored student details
   printf("The Area of Rectangle:%f\n",r1.breadth*r1.length);
   printf("The perimeter of Rectangle:%f",2*(r1.breadth+r1.length));
   return 0;
}
