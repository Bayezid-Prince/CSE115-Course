#include<stdio.h>
int main(){
   int s1,s2,s3;
   int a,b,c;
   printf("enter 3 sides of a triangle\n");
   scanf("%d",&s1);
   scanf("%d",&s2);
   scanf("%d",&s3);
   printf("enter 3 angles of a triangle \n");
   scanf("%d",&a);
   scanf("%d",&b);
   scanf("%d",&c);
   if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
       printf("not a triangle\n");
   else if (s1 + s2 >= s3 && s1 + s3 >= s2 && s2 + s3 >= s1){
       if(a+b+c == 180)
           printf("it is a triangle\n");
       else if(a+b+c != 180)
           printf("it is not a triangle\n");
   }
}
