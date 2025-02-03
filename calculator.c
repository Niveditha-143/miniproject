#include<stdio.h>
float add(float a,float b){return a+b;}
float subtract(float a,float b){return a-b;}
float multiply(float a,float b){return a*b;}
float divide(float a,float b){return  b!=0?a/b:0;}
int main(){
    float num1,num2;
    char op;
    float(*operation) (float,float);
    printf("enter first number:");
    scanf("%f",&num1);
    printf("enter operator(+,-,*,/):");
    scanf(" %c",&op);
    printf("\nenter second number:");
    scanf("%f",&num2);
    switch(op) {
        case'+':operation = add; break;
        case'-':operation = subtract; break;
        case'*':operation = multiply; break;
        case'/':operation = divide; break;
        default:printf("invalid operator ! \n");
        return 1;
    }
    printf("result :%2f\n",operation(num1,num2));
    return 0;
}
