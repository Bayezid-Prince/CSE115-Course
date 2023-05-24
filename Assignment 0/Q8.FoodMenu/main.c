#include<stdio.h>
#include<math.h>
int main(){
    float a, b, c;
    float dis, r1, r2, real, img;
    printf("enter a,b,c: \n ");
    scanf("%f %f %f", &a, &b, &c);
    dis = b * b - 4 * a * c;
    if (dis > 0){
        r1 = (-b + sqrt(dis)) / (2 * a);
        r2 = (-b - sqrt(dis)) / (2 * a);
        printf("root1 = %.2f and root2 = %.2f \n", r1, r2);
    }
    else if (dis == 0){
        r1 = r2 = -b / (2 * a);
        printf("root1 = %.2f and root2 = %.2f", r1, r2);
    }
    else {
        real = -b / (2 * a);
        img = sqrt(-dis) / (2 * a);
        printf("root1 = %.2f + %.2fi and root2 = %.2f - %.2fi ", real, img, real, img);
    }
    return 0;
}
