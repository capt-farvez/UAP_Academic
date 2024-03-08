#include<stdio.h>
int sum(int num){
    if(num!=0)
        return (num%10)+sum(num/10);
    else 
        return 0;
}
int main(){
    int number;
    printf("Enter the Number. \n");
    scanf("%d",&number);
    int res= sum(number);
    printf("Summation of %d by digit is %d",number, res);
}