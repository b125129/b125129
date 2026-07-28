#include<stdio.h>

typedef struct{
   float inch ;
   float feet ;
}distance;

void main(){
    distance d1,d2;

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

    printf("\nTotal Distance = %f Feet %f Inches\n", d1.feet + d2.feet, d1.inch + d2.inch);
}
