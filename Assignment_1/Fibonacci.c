#include<stdio.h>

int Fibonacci(int);

int main(){
    //Initializing values and storing them
    int value, a = 0, i;
    printf("Enter number of terms: ");
    scanf("%d",&value);
    //Checking Fibonacci Series using For Loop
    printf("\nFibonacci series: \n");
    for(int i = 1; i <= value; i++){
        printf("%d\n", Fibonacci(a));
        a++;
    }
    return 0;
}
//Function to check Fibonacci
int Fibonacci(int n){
    if(n == 0)
    return 0;
    else if(n == 1)
    return 1;
    else
    return(Fibonacci(n - 1) + Fibonacci(n - 2));
}
