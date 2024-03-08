#include <stdio.h>
int fact(int num){
    if(num==1)
        return 1;
     return num*fact(num-1);
}

int main(){
    int number;
    printf("Enter the number.\n");
    scanf("%d",&number);
    int result = fact(number);
    printf("Factorial of %d is = %d \n",number, result);
}