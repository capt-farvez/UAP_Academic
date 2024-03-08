#include <bits/stdc++.h>
using namespace std;
void fMerge(int arr[], int L, int m, int r)
{
    int i, j, k;

    int n1 = m - L + 1;
    int n2 = r - m;
    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[L + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = L;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int L, int r)
{
    if (L < r)
    {
        int m = L + (r - L) / 2;
        mergesort(arr, L, m);     // left
        mergesort(arr, m + 1, r); // right

        fMerge(arr, L, m, r);
    }
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
    mergesort(arr, 0, size - 1);

    cout << endl
         << "After Sort...." << endl;
    for (p = 0; p < size; p++)
    {
        cout << arr[p] << " ";
    }
}
