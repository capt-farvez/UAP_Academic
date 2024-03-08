#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i, j;
    for(i = low-1, j = low; j < high; j++){
        if(arr[j] < pivot){
            i+=1;
            swap(arr[i], arr[j]);
        }
    }
    i+=1;
    swap(arr[i], arr[high]);
    return i;
}

void quick_sort(int arr[], int low, int high){
    if(low >= high){
        return;
    }
    int p = partition(arr, low, high);
    quick_sort(arr, low, p-1);
    quick_sort(arr, p+1, high);
}


int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}