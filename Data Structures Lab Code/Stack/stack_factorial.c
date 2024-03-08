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
    printf("Enter the number : ");
    int num, sum=1;
    scanf("%d",&num);

    for( int i=1; i<=num; i++){
        push(i);
    }
    printf("Stack is : ");
    for(int i=0; i<=top; i++){
        printf("%d ",stack[i]);
        sum= sum* stack[i];
    }

    printf("\nFactorial of %d is : %d \n",num,sum);
}