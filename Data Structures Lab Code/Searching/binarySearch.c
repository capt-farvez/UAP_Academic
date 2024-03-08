#include <stdio.h>
int binarySearch(int array[] , int size, int num){
    int mid, max=size, min=1;
    for(int i=0; i<size; i++){
        mid = (max+min)/2;
        if(array[mid]==num){
            return num;
        }
        else if(array[mid]>num){
            max=mid;
        }
        else {
            min= mid;
        }
    }
    return -1;
}
int main(){
    printf("Enter the Size of Array..\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements...\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number you want to search..\n");
    int num;
    scanf("%d",&num);
    int check= binarySearch(arr, n, num);
    if(check==-1){
        printf("%d not found.\n",num);
    }
    else {
        printf("%d is found.\n",num);
    }
}