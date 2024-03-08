#include <stdio.h>
int linearSearch(int array[], int size, int num){
  for(int i=0; i<size; i++){
      if(array[i]==num){
          return i;
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
    int check= linearSearch(arr, n, num);
    if(check==-1){
        printf("%d not found.\n",num);
    }
    else {
        printf("%d is found at %d th position.\n",num,check);
    }
}