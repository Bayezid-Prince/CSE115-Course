#include<stdio.h>

int main(){
    //Initializing the values and storing them
    int a, b;
    printf("Enter value1: ");
    scanf("%d",&a);
    printf("Enter value2: ");
    scanf("%d",&b);
    //Values before swapping
    printf("\nBefore swapping,\n\nvalue of value1 = %d and value2 = %d",a,b);
    a = a + b; 
    b = a - b;
    a = a - b;
    //Values after swapping and displaying result
    printf("\n\nAfter swapping, \n\nvalue of value1 = %d and value2 = %d",a,b);
    printf("\n");
    return 0;
}
