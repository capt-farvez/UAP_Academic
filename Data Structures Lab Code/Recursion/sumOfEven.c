#include <stdio.h>
int sum(int n1, int n2){
    if(n1>n2)
        return 0;
    else
        return n1+sum(n1+2, n2);
}

int main(){
    int n1=2, n2;
    printf("Enter the last number.\n");
    scanf("%d",&n2);
    int result = sum(n1, n2);
    printf("Summation of Even numbers from 1 to %d is = %d \n",n2, result);

}