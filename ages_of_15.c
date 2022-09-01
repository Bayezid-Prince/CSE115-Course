#include<stdio.h>
int main(){
    //Initializing values and storing them
    int age, i = 1, count = 0;
    printf("Enter the age of 15 persons: \n");
    //Checking age
    while(i <= 15){
        printf("Enter the age of person %d: ",i);
        scanf("%d",&age);
        i++;
        if(age < 40||age > 60)
        continue;
        count++;
    }
    //Displaying result
    printf("Number of persons whose age is between 40 and 60: %d",count);
    return 0;
}
