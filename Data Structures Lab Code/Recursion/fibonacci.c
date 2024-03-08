#include<stdio.h>
int fibo(int num){
    if(num<=1)
        return num;
    return fibo(num-1)+fibo(num-2);
}
int main(){
    int position;
    printf("Enter the last position. \n");
    scanf("%d",&position);
    printf("Sum of Fibonacci series at position %d is %d \n",position,fibo(position));
}