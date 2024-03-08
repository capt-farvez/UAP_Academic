#include <stdio.h>
int top=-1;
int max = 100;
int stack[100];

int isFull(){
    if (top== (max-1)){
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int peek(){
    return stack[top];
}

int pop(){
    int x;
    if(isEmpty()){
        printf("Stack is Empty. \n");
    }
    else {
        x=stack[top];
        top-=1;
        return x;  
    }
}

int push(int data){
    if(isFull()){
        printf("stack is Full. \n");
    }
    else {
        top+=1;
        stack[top]=data;
    }
}

int main (){
    printf("Enter The last elements position : ");
    int n, sum = 0;
    scanf("%d",&n);
    push(0);
    push(1);

    for ( int i = 2; i<n; i++){
        int fst = i-2;
        int sec = i-1;
        stack[i]= stack[fst] + stack[sec];
        push(stack[i]);
    }
    printf("Stack is : ");
    printf("\n");
    for(int i=0;i<=top; i++){
        printf("%d ",stack[i]);
        sum=sum+stack[i];
    }
    printf("\nThe Summation of First %d numbers in fibonacci series is %d \n",n,sum);
}
