#include <bits/stdc++.h>
using namespace std;

int CrossSum(int arr[], int low, int mid, int high)
{
    int sum = 0, i;
    int lsum = INT_MIN;
    int rsum = INT_MIN;

    for (i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (lsum < sum)
            lsum = sum;
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (rsum < sum)
            rsum = sum;
    }
    return lsum + rsum;
}

int mss(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];
    int mid = (low + high) / 2;
    int rsum = mss(arr, mid + 1, high);
    int lsum = mss(arr, low, mid);
    int cross = CrossSum(arr, low, mid, high);
    return max(max(lsum, rsum), cross);
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
    int result = mss(arr, 0, size - 1);
    printf("Maximum subarray sum is : %d", result);
    return 0;
}