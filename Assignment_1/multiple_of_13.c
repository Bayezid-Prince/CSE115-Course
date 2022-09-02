#include<stdio.h>
int main(){
    //Initializing values and storing them
    int value;
    printf("Enter a number: ");
    scanf("%d",&value);
    //Checking if the number is multiple by 13 and displaying result
    if(value % 13 == 0)
        printf("%d is a multiple of 13",value);
    else
        printf("%d is not a multiple of 13",value);
    printf("\n");
    return 0;
}
