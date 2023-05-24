#include<stdio.h>
int main(){
   int num;
   printf("enter 0 to exit\n");
   while(1){
        printf("enter a number\n");
        scanf("%d",&num);
        if(num>0)
            printf("%d is a positive number\n",num);
       else if(num<0)
            printf("%d is a negative number\n",num);
       else if(num ==0)
            break;
    }
   printf("exit....\n");
}
