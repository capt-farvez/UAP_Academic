#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int maxSubArraySum(int a[], int size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int smallestSumSubarr(int arr[], int n)
{
    int min_ending_here = INT_MAX;
    int min_so_far = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (min_ending_here > 0)
        {
            min_ending_here = arr[i];
        }

        else
        {
            min_ending_here += arr[i];
        }
        min_so_far = min(min_so_far, min_ending_here);
    }

    return min_so_far;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int a[size];
        for (int i = 0; i < size; i++)
        {
            int x;
            cin >> x;
            a[i] = x;
        }
        // int n = sizeof(a)/sizeof(a[0]);
        int max_sum = maxSubArraySum(a, size);
        int smallest_sum = smallestSumSubarr(a, size);
        cout << smallest_sum << " " << max_sum << endl;
    }
    return 0;
}
