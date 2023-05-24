#include <stdio.h>
int main(){
    int price,kg,totalAmount=0,totalKg=0;
    float avg;
    do{
        printf("Enter amount (in kg): ");
        scanf("%d",&kg);
        if(kg<0){
        printf("Invalid input, enter a positive number\n");
        continue;
        }
    else if(kg==0){
    break;
    }
    else{
        printf("Enter price: ");
        scanf("%d",&price);
        if(price<0){//if price less than 0 then print error message
        printf("Invalid input, enter a positive number\n");
        continue;
    }
    else{
        totalKg=totalKg+kg;
        totalAmount=totalAmount+price;
        }
      }
    }
    while(price!=0);
    avg=totalAmount/totalKg;
    printf("The total in (kg):%d, Total pric: %d, Average price per kg: %.2f", totalKg,totalAmount,avg);
    return 0;
}
