#include<stdio.h>

typedef struct{
   float length ;
   float breadth ;
}rectangle;

void main(){
    rectangle r1;
    printf("Enter Length : ");
    scanf("%f",&r1.length);
    printf("Enter Breadth : ");
    scanf("%f",&r1.breadth);

    printf("The Area of Rectangle:%f\n",r1.breadth*r1.length);
    printf("The perimeter of Rectangle:%f",2*(r1.breadth+r1.length));
}
