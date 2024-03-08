#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(arr, l, h);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, h);
    }
}
int partition(int arr[], int l, int h)
{
    int pivot, i, j, temp;
    pivot = arr[l];
    i = l;
    j = h + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot && i <= h);

        do
        {
            j--;
        } while (pivot < arr[j]);

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[l] = arr[j];
    arr[j] = pivot;
    return j;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    // size=sizeof(arr)/sizeof (arr[0]);
    cout << "Before Sort..." << endl;
    int p;
    for (p = 0; p < size; p++)
    {
        cout << arr[p] << " ";
    }

    quickSort(arr, 0, size - 1);

    cout << endl
         << "After Sort...." << endl;
    for (p = 0; p < size; p++)
    {
        cout << arr[p] << " ";
    }
}

// #include <stdio.h>
// void quick_sort(int[],int,int);
// int partition(int[],int,int);
// void printArray(int A[], int n);

// int main()
// {
//     int A[] = {10, 16, 8, 12,15,6,3,9,5}, n,i;
//     n = sizeof(A) / sizeof(A[0]);

//     printf("Before sorting :\n");
//     printArray(A, n);

//     quick_sort(A,0,n-1);

//     printf("\nAfter sorting:\n");
//     printArray(A, n);
//     return 0;
// }

// void printArray(int A[], int n)
// {
//     int i;
//     for(i=0; i<n; i++)
//         printf("%d ",A[i]);
// }

// void quick_sort(int A[],int l,int h)
// {
//     int j;
//     if(l<h)
//     {
//         j=partition(A,l,h);
//         quick_sort(A,l,j-1);
//         quick_sort(A,j+1,h);
//     }
// }

// int partition(int A[],int l,int h)
// {
//     int pivot,i,j,temp;
//     pivot=A[l];
//     i=l;
//     j=h+1;
//     while(i<j)
//     {
//         do
//         {
//             i++;
//         }
//         while(A[i]<pivot && i<=h);

//         do
//         {
//             j--;
//         }
//         while(pivot<A[j]);

//         if(i<j)
//         {
//             temp=A[i];
//             A[i]=A[j];
//             A[j]=temp;
//         }
//     }
//     A[l]=A[j];
//     A[j]=pivot;
//     return j;
// }
