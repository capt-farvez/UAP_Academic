#include <stdio.h>
int top=-1;
int max = 10;
int stack[10];

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

int main(){
    while(1){
     printf(" Enter 1 for Check Empty or Not. \n Enter 2 for Check full or not. \n Enter 3 for peek. \n Enter 4 for push. \n Enter 5 for pop. \n Enter 0 for Return the System.\n");
    int check;
    scanf("%d",&check);
    switch(check){
        case 1:
        if(isEmpty()){
            printf("Stack is Empty. \n");
        }
        else {
            printf("Stack is not empty and stack is : ");
            for(int i=0; i<top+1; i++){
                printf("%d ",stack[i]);
            }
        }
        printf("\n");
        break;

        case 2:
        if(isFull()){
            printf("Stack is Full. \n");
        }
        else {
             printf("Stack is not full and stack is : ");
            for(int i=0; i<top+1; i++){
                printf("%d ",stack[i]);
            }
        }
        printf("\n");
        break;

        case 3:
        {
         int num= peek();
         printf("%d",num);
         break; 
         }

        case 4:
        isFull();
        printf("Enter The number you want to push. \n");
        int a;
        scanf("%d",&a);
        push(a);
        printf("last push number : %d \n",stack[top]);
        printf("Stack is : ");
         for(int i=0; i<top+1; i++){
                printf("%d ",stack[i]);
            }
        printf("\n");
        break;

        case 5:
    
        pop();
        printf("Stack is : ");
         for(int i=0; i<top+1; i++){
                printf("%d ",stack[i]);
            }
        printf("\n");
        break;

        case 0:
        return 0;


    }
    
    }

}