#include <stdio.h>
int sum(int n){
    if(n!=0)
        return n+sum(n-1);
    
    else
        return 0;
}

int main(){
    int number;
    printf("Enter the last number.\n");
    scanf("%d",&number);
    int result = sum(number);
    printf("Summation of 1 to %d is = %d \n",number, result);
}