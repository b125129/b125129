#include<stdio.h> //included library for standarad input and output

//define the required structure
typedef struct{
   float inch ;
   float feet ;
}distance;

void main(){
    distance d1,d2;   // Declare two variable d1 and d2 of type distant

    // Input values from the user and store them in structure member
    printf("Enter first distance:\n");
    printf("Feet:");
    scanf("%f",&d1.feet);
    printf("Inches : ");
    scanf("%f",&d1.inch);

    
    printf("Enter second distance:\n");
    printf("Feet:");
    scanf("%f",&d2.feet);
    printf("Inches : ");
    scanf("%f",&d2.inch);

    // Display the stored student details
    printf("\nTotal Distance = %f Feet %f Inches\n", d1.feet + d2.feet, d1.inch + d2.inch);
}
