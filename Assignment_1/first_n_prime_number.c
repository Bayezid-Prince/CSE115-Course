#include<stdio.h>

int main(){
    //Initialing values and storing them
    int number, i = 3, c, j;
    printf("Enter a number: ");
    scanf("%d", &number);
    //Checking prime numbers using Loop and printing result using if function
    if(number >= 1){
        printf("\nFirst %d prime numbers are:  ", number);
        printf("2 ");
    }
    for(c = 2; c <= number; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0)
                break;
        }
        if(j == i){
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    return 0;
}
