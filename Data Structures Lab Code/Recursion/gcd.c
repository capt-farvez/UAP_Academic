#include<stdio.h>
int findGCD(int a, int b){
    while (a!=b){
        if(a>b)
            return findGCD(a-b, b);
        else 
            return findGCD(a, b-a);
    }
    return a;
}
int main (){
    int num1, num2;
    printf("Enter two numbers. \n");
    scanf("%d%d",&num1, &num2);
    printf("The GCD of %d and %d is %d \n",num1, num2, findGCD(num1, num2));
}