#include<bits/stdc++.h>
using namespace std;

int bSearch(int array[], int min, int max, int num){
        if(max>=min){
            int mid=min+(max-min)/2;
            
            if(array[mid]==num){
                return mid;
            }
            if(array[mid]>num){
                return bSearch(array, min, mid-1, num);
            }
            else{
                return bSearch(array, mid+1, max, num);
            }
        }
        return -1;

    }

int main(){
    int arr1[]={10, 12,13,15,20,25,30,35,40,50};
    int size=sizeof(arr1);
    int x=bSearch(arr1, 0, size-1, 15);
    if(x==-1){
        cout<<" Not Found"<<endl;
    }
    else{
        cout<<" Found at position : "<<x+1<<endl;
    }
    
}