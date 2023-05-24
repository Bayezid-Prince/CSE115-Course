#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char hex[20];
    long long decimal = 0, place = 1;
    int i = 0, val, len;
    printf("Enter hex number: ");
    gets(hex);
    len = strlen(hex);
    len--;
    for(i=0; hex[i]!='\0'; i++){
        if(hex[i]>='0' && hex[i]<='9'){
            val = hex[i] - 48;
    }
    else if(hex[i]>='a' && hex[i]<='f'){
        val = hex[i] - 97 + 10;
    }
    else if(hex[i]>='A' && hex[i]<='F')
    {
        val = hex[i] - 65 + 10;
    }
    decimal += val * pow(16, len);
    len--;
    }
    printf("Hex number = %s\n", hex);
    printf("Decimal number = %lld", decimal);
    return 0;
}
